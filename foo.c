#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;


/* ------------- my code here ---------------------------*/

// initial size of arrays. can be reallocated
#define MAX_BOOK_PER_SHELF 1100

// keep track of the free spot on each shelf
int* size_of_shelf;

// type 1 query
void insert_book(int shelf, int pages) {
    total_number_of_pages[shelf][size_of_shelf[shelf]] = pages;
    size_of_shelf[shelf]++;
    total_number_of_books[shelf]++;
}

void initializing_arrays(int n_shelves) {
    total_number_of_books = calloc(n_shelves, sizeof(int));
    size_of_shelf = calloc(n_shelves, sizeof(int));
    int i;
    total_number_of_pages = malloc(n_shelves * sizeof(int*));
    for (i = 0; i < n_shelves; i++) {
        total_number_of_pages[i] = malloc(MAX_BOOK_PER_SHELF * sizeof(int));
    }
}

/* ------------- my code here ---------------------------*/

int main()
{
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);
    
    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);
    


    /* ------------- my code here ---------------------------*/
    initializing_arrays(total_number_of_shelves);
    /* ------------- my code here ---------------------------*/

    
    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            scanf("%d %d", &x, &y);

            /* ------------- my code here ---------------------------*/
            insert_book(x, y);
            /* ------------- my code here ---------------------------*/

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}