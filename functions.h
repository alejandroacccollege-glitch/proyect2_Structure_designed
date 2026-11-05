#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
/* Cabecera de las implementaciones (archivo functions.c) 
además de las cosas que deben ser públicas para el archivo proyect2.c*/ 
struct strNode {
    char pairedDelimiter;
    struct strNode *prior;
}; // Crea una estructura de lo que tiene un nodo
typedef struct strNode *Node; // Apunta a la estructura nodo para crear nodos

struct strStack {
    Node top;
    int size;
}; // Crea una estructura de lo que tiene un stack
typedef struct strStack *Stack; // Apunta a la estructura stack para crear Stacks

typedef enum {False, True} Bool;
void push(Stack, char); // Prototipo de la implementación "push" que esta en (functions.c)
char pop(Stack); // Prototipo de la implementación "pop" que esta en (functions.c)

#endif