#include <stdio.h>
#include <stdlib.h>
#include "proyect2.h"
// Ejercicio 1

void createMatrix(char**** matrix, unsigned int** counts, char* words[], int numWords) {
    
    *counts = (unsigned int*) calloc(26, sizeof(unsigned int)); //Creamos contadores para cada fila (26) y todos los inicializamos en 0

    
    for (int i = 0; i < numWords; i++) {
        int row = words[i][0] - 'a';
        (*counts)[row]++;
    } // En el ciclo for , a i le restamos 'a', para saber a que count le vamos a aumentar, si 'b' - 'a' = 1, va a la fila 1 
    //Despues de saber a que fila ir, el contador de esa fila se le suma.
    
    
    *matrix = (char***) malloc(26 * sizeof(char**));  //Creamos 26 apuntadores para cada letra del abecedario ingles.

    
    for (int i = 0; i < 26; i++) {
        if ((*counts)[i] > 0) { //Si en esa fila el contador es mayor que 0 entramos en este if
            (*matrix)[i] = (char**) malloc((*counts)[i] * sizeof(char*)); //Reservamos la memoria para poner las palabras
        } else {
            (*matrix)[i] = NULL; // Si contador esta en 0, entonces en ese espacio no apartamos nada ya que no se va a reservar nada.
        }
    }

    
    int pos[26] = {0};  // Creamos un arreglo auxiliar(todos los lugares inician en 0), nos facilitará poder ver que columna esta vacía 

    
    for (int i = 0; i < numWords; i++) { //Recorre todas las palbras de words
        int row = words[i][0] - 'a'; //Volvemos a tomar la primera letra de cada palabra para acomodarla
        int col = pos[row]; // Vemos cual es la siguiente columna disponible para acomodar otra palabra que inicie con la misma letra que otra.
        (*matrix)[row][col] = words[i]; // Guardamos la palabra en donde debe de ir 
        pos[row]++; //Nos movemos a la siguiente columna para acomodar las demas palabras donde deben de ir.
    }
}

// Ejercicio 3
Bool isBalanced(char filename[])
{

    FILE *fileOpened = fopen(filename, "r"); // Abre el archivo existente en modo lectura
    
    if (!fileOpened)
        return False; /*Si directamente no pudo abrir el archivo debido a que no existe
        o por alguna otra razón, directamente devuelve falso ya que sería inecesario */  

    Stack signs = (Stack) malloc(sizeof(struct strStack));
    signs->top = NULL;
    signs->size = 0; /* De la línea 15 a 17 se crea un Stack para almacenar los símbolos*/ 


    int currentChar = fgetc(fileOpened); // Lee el carácter actual mientras aún haya

    while (!feof(fileOpened)) // Mientras no se escuentre el fin del archivo
    {
        if (currentChar == '<' || currentChar == '{' || currentChar == '(' || currentChar == '[')
        { 
            push(signs, currentChar); /*Si al leer el carácter actual se topa con alguno de los delimitadores 
            de apertura ('<', '{', '(', '['), lo empuja al stack para ver si se completa posteriormente */ 
        }
        else if (currentChar == '>' || currentChar == '}' || currentChar == ')' || currentChar == ']')
        { // Cuando se topa con los que cierran los delimitadores procede a lo siguiente:
            if (signs->top == NULL)
                return False; // Primero, si la pila está vacía devuelve falso ya que no hay con que verificar
            
                char stackChar = signs->top->pairedDelimiter; /* Se revisa el delimitador que se encuentra
                almacenado en el Stack */
            switch (currentChar)
            { /*En cada caso si el delimitador (de cierre) actual no tiene su signo de apertura almacenado en 
                el Stack devuelve directamente falso ya que con uno que no tenga su cierre ya no está balanceado, 
                si no se cumple la condición anterior se saca el delimitador de apertura, es decir va vaciando 
                el Stack */
            case '>':
                if (stackChar != '<')
                    return False;
                pop(signs);
                break;
            case '}':
                if (stackChar != '{')
                    return False;
                pop(signs);
                break;
            case ')':
                if (stackChar != '(')
                    return False;
                pop(signs);
                break;
            case ']':
                if (stackChar != '[')
                    return False;
                pop(signs);
                break;
            }
        }
        currentChar = fgetc(fileOpened); /*Después de hacer las verificaciones anteriores, se pasa al 
        siguiente carácter para volver a empezar el while*/ 
    }
    fclose(fileOpened); // Cierra el archivo
    if (signs -> size == 0) return True; /* Al vaciarse conforme encuantra pares, al final si encuentra 
    un cierre para cada cada apertura termina el stack vacío, por lo que será verdadero el hecho de
    estar balanceado */
    return False; /* Caso contrario al anterior, devuelve falso ya que se quedaron aquellas aperturas 
    que no encintraron cierre */
}