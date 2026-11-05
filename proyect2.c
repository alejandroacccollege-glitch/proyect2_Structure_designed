#include <stdio.h>
#include <stdlib.h>
#include "proyect2.h"

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