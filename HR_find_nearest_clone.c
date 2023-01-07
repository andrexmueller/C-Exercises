#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */



/*                       MY CODE STARTS HERE                                                     */

#define min(a, b) (a)<(b)?(a):(b)

typedef struct node_t {
    int node_id;
    long color;
    int* neibors;
    int neibors_count;
} node_t;

node_t init_node(int node_id, long color) {
    node_t node;
    node.node_id = node_id;
    node.color = color;
    node.neibors_count = 0;
    node.neibors = calloc(1, sizeof(int));
    return node;
}

void connect_nodes(node_t* v, node_t* w) {
    v->neibors_count += 1;
    w->neibors_count += 1;
    v->neibors = realloc(v->neibors, v->neibors_count * sizeof(int));
    w->neibors = realloc(w->neibors, w->neibors_count * sizeof(int));
    v->neibors[v->neibors_count-1] = w->node_id;
    w->neibors[w->neibors_count-1] = v->node_id;
}


int BFS(const node_t* graph, int graph_nodes, int start, int color) {    
    int path[graph_nodes+1];
    for (int i = 0; i <= graph_nodes; i++)
        path[i] = -1;
    int visited[graph_nodes+1];
    for (int i = 0; i <= graph_nodes; i++)
        visited[i] = false;
    int queue[graph_nodes+1];
    int q_start = 0, q_end = 1;
    queue[q_start] = start;
    int last_node = start;
    int current, neibor;
    while (q_start < q_end) {
        current = queue[q_start++];
        visited[current] = true;
        for (int i = 0; i < graph[current].neibors_count; i++) {
            neibor = graph[current].neibors[i];
            if (!visited[neibor]) {
                path[neibor] = current;
                if (graph[neibor].color == color) {
                    last_node = neibor;
                    break;
                }
                queue[q_end++] = neibor;
            }
        }
    }
    if (last_node == start) 
        return -1;
    int path_len = 0;
    while (last_node != start) {
        last_node = path[last_node];
        path_len++;
    }
    return path_len;
}


int findShortest(int graph_nodes, int graph_edges, int* graph_from, int* graph_to, int ids_count, long* ids, int val) {
    
    
    node_t* graph = calloc(graph_nodes + 1, sizeof(node_t));
    
    for (int i = 1; i < graph_nodes+1; i++) {
        graph[i] = init_node(i, ids[i-1]); 
    
    }

    for (int i = 0; i < graph_edges; i++) {
        connect_nodes(&graph[graph_from[i]], &graph[graph_to[i]]);
    }

    int min_distance = graph_nodes + 1;
    bool at_least_two_colors = false;
    int dist;
         
    for (int node = 1; node <= graph_nodes; node++) {
        if (graph[node].color == val) {
            at_least_two_colors = true;
            dist = BFS(graph, graph_nodes, node, val);
            min_distance = min(dist, min_distance);    
        }
    }
    
    if(!at_least_two_colors) return -1;
    return min_distance;
    
}



/*                       MY CODE ENDS HERE                                                       */


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** graph_nodes_edges = split_string(readline());

    char* graph_nodes_endptr;
    char* graph_nodes_str = graph_nodes_edges[0];
    int graph_nodes = strtol(graph_nodes_str, &graph_nodes_endptr, 10);

    if (graph_nodes_endptr == graph_nodes_str || *graph_nodes_endptr != '\0') { exit(EXIT_FAILURE); }

    char* graph_edges_endptr;
    char* graph_edges_str = graph_nodes_edges[1];
    int graph_edges = strtol(graph_edges_str, &graph_edges_endptr, 10);

    if (graph_edges_endptr == graph_edges_str || *graph_edges_endptr != '\0') { exit(EXIT_FAILURE); }

    int graph_from[graph_edges];
    int graph_to[graph_edges];

    for (int graph_i = 0; graph_i < graph_edges; graph_i++) {
        char** graph_from_to = split_string(readline());

        char* graph_from_temp_endptr;
        char* graph_from_temp_str = graph_from_to[0];
        int graph_from_temp = strtol(graph_from_temp_str, &graph_from_temp_endptr, 10);

        if (graph_from_temp_endptr == graph_from_temp_str || *graph_from_temp_endptr != '\0') { exit(EXIT_FAILURE); }

        char* graph_to_temp_endptr;
        char* graph_to_temp_str = graph_from_to[1];
        int graph_to_temp = strtol(graph_to_temp_str, &graph_to_temp_endptr, 10);

        if (graph_to_temp_endptr == graph_to_temp_str || *graph_to_temp_endptr != '\0') { exit(EXIT_FAILURE); }

        graph_from[graph_i] = graph_from_temp;
        graph_to[graph_i] = graph_to_temp;
    }

    char** ids_temp = split_string(readline());

    long* ids = malloc(graph_nodes * sizeof(long));

    for (int i = 0; i < graph_nodes; i++) {
        char* ids_item_endptr;
        char* ids_item_str = *(ids_temp + i);
        long ids_item = strtol(ids_item_str, &ids_item_endptr, 10);

        if (ids_item_endptr == ids_item_str || *ids_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(ids + i) = ids_item;
    }

    int ids_count = graph_nodes;

    char* val_endptr;
    char* val_str = readline();
    int val = strtol(val_str, &val_endptr, 10);

    if (val_endptr == val_str || *val_endptr != '\0') { exit(EXIT_FAILURE); }

    int ans = findShortest(graph_nodes, graph_edges, graph_from, graph_to, ids_count, ids, val);

    fprintf(fptr, "%d\n", ans);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
