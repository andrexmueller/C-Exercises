#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}




/******************************************************************************************************/


void ver_tamanhos(char* texto, int* n_par, int* n_sen, int* n_pal) {
    for (int i = 0; i < strlen(texto); i++) {
        switch (texto[i]) {
            case ' ': {
                *n_pal += 1;
                break;
            }
            case '.': {
                *n_pal += 1;
                *n_sen += 1;
                break;
            }
            case '\n': {
                *n_par += 1;
                break;
            }
        }
    }
    return;
}

int adiciona_palavra(char** sentenca, int ipal, char* tmp_palavra, int* cursor) {
    tmp_palavra[*cursor] = '\0';
    int size = (strlen(tmp_palavra) + 1) * sizeof(char);
    char* palavra = malloc(size);
    memcpy(palavra, tmp_palavra, size);
    sentenca[ipal] = palavra;
    *cursor = 0;
    return 1;
}


void parse_texto(char* texto, char**** documento) {
    
    char tmp_palavra[1000];
    int cursor = 0, ipar = 0, isen = 0, ipal = 0;
    
    for (int i = 0; i < strlen(texto); i++) {
        switch (texto[i]) {
            case ' ': {
                ipal += adiciona_palavra(documento[ipar][isen], ipal, tmp_palavra, &cursor);
                break;
            }
            case '.': {
                adiciona_palavra(documento[ipar][isen], ipal, tmp_palavra, &cursor);
                ipal = 0;
                isen++;
                break;
            }
            case '\n': {
                isen = 0;
                ipar++;
                break;
            }
            default: {
                tmp_palavra[cursor] = texto[i];
                cursor++;
            }
        }
    }
    return;  
}



char**** get_document(char* text) {

    int num_paragrafos = 1, num_sentencas = 0, num_palavras = 0;
    ver_tamanhos(text, &num_paragrafos, &num_sentencas, &num_palavras);
    
    char**** documento = malloc(num_paragrafos * sizeof(char***));
    for (int i = 0; i < num_paragrafos; i++) {
        documento[i] = malloc(num_sentencas * sizeof(char**));
        for (int j = 0; j <num_sentencas; j++) {
            documento[i][j] = malloc(num_palavras * sizeof(char*));
        }
    }

    parse_texto(text, documento);

    return documento;
}


void libera_memoria(char****document, int n_par, int n_sen, int n_pal) {
    for (int i = 0; i < n_par; i++) {
        for (int j = 0; j <n_sen; j++) {
            for (int k = 0; k < n_pal; k++) {    
                free(document[i][j][k]);
            }
            free(document[i][j]);
        }
        free(document[i]);
    }
    free(document);
}


/******************************************************************************************************/

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);
    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     

    printf("\n ======== liberando memoria =========================\n");
    int num_paragrafos = 1, num_sentencas = 0, num_palavras = 0;
    ver_tamanhos(text, &num_paragrafos, &num_sentencas, &num_palavras);
    libera_memoria(document, num_paragrafos, num_sentencas, num_palavras);
    printf("\n ======== memoria liberada com sucesso ==============\n");
    return 0;
}