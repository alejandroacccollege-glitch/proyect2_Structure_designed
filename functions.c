#include <stdlib.h>
#include "functions.h"
// Funciones que pueden ser usadas pora otras partes del proyecto (Para el archivo proyect2.c)
//Hola
void push(Stack stack, char symbol) {
    
    Node newNode = (Node) malloc(sizeof(struct strNode));
    if (newNode == NULL) return;
    newNode->pairedDelimiter = symbol;
    newNode->prior = stack->top;
    stack->top = newNode;
    stack->size++;
} // Se encarga de agregar datos al stack

char pop(Stack stack) {
    if (stack->top == NULL) {
        return '\0';
    }

    Node temp = stack->top;
    char value = temp->pairedDelimiter; 

    stack->top = temp->prior;
    free(temp);               
    stack->size--;                 

    return value;   
} //Se encarga de devolver datos almacenados en el stack