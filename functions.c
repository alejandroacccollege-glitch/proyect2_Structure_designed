#include "functions.h"

void push(Stack stack, char symbol) {
    
    Node newNode = (Node) malloc(sizeof(struct strNode));
    if (newNode == NULL) return;
    newNode->pairedDelimiter = symbol;
    newNode->prior = stack->top;
    stack->top = newNode;
    stack->size++;
}

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
}