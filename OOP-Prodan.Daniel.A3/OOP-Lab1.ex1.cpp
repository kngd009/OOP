#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>

int conversie(char* sir) {
    int result = 0;
    while (*sir != '\0' and *sir != '\n') {
        result = result * 10 + (*sir - '0');
        sir++;
    }
    return result;
}

int main() {
    FILE* fisier;
    char linie[100];
    int suma = 0;

    fisier = fopen("in.txt", "r");
    if (fisier == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        exit(1);
    }

    while (fgets(linie, sizeof(linie), fisier)) {
        suma += conversie(linie);
    }

    printf("%d\n", suma);

    fclose(fisier);

    return 0;
}
