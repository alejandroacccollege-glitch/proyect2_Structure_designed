#include <stdio.h>
#include <stdlib.h>
#include "proyect2.h"

int main()
{
    // Ejercicio 1
    printf("Ejercicio 1\n");
    char ***matrix = NULL;
    unsigned int *counts = NULL;
    char *words[] = {
        "int",
        "main",
        "double",
        "char",
        "else",
        "long",
        "case",
        "for",
        "while",
        "continue",
        "if",
        "float",
        "do",
        "break",
        "switch",
    };

    createMatrix(&matrix, &counts, words, 15);

    for (int i = 0; i < 26; i++)
    {
        if (counts[i] == 0)
            continue;
        for (int j = 0; j < counts[i]; j++)
        {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 26; i++)
    {
        if (matrix[i] != NULL)
        {
            free(matrix[i]);
        }
    }
    free(matrix);
    free(counts);

    printf("Ejercicio 2\n");
    // Ejercicio 2
    Chack k = chack_create(10);
    chack_print(k);
    for (char c = 'a'; c <= 'z'; c++)
        chack_push(k, c);
    printf("Pop: %c\n", chack_pop(k));
    printf("Top: %c\n", chack_top(k));
    chack_print(k);
    chack_clear(k);
    chack_print(k);

    // Ejercicio 3
    printf("Ejercicio 3\n");
    if (isBalanced("TestFileExercise3.txt") == True)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    } // Se prueba el ejercicio 3 con el archivo dado

    return 0;
}