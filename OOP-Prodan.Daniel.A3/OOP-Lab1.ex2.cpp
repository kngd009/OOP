#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

void swap_strings(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char propozitie[MAX_LENGTH * MAX_WORDS];
    char* cuvinte[MAX_WORDS];
    int i, j, num_words;

    printf("Introduceti o propozitie: ");
    scanf("%[^\n]", propozitie);

  
    num_words = 0;
    cuvinte[num_words] = strtok(propozitie, " ");
    while (cuvinte[num_words] != NULL) {
        num_words++;
        cuvinte[num_words] = strtok(NULL, " ");
    }

    /* bubble sort */
    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            int len_j = strlen(cuvinte[j]);
            int len_jp1 = strlen(cuvinte[j + 1]);
            if (len_j < len_jp1 || (len_j == len_jp1 && strcmp(cuvinte[j], cuvinte[j + 1]) > 0)) {
                swap_strings(&cuvinte[j], &cuvinte[j + 1]);
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        printf("%s\n", cuvinte[i]);
    }

    return 0;
}