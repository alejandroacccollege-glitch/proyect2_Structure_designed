#include <stdlib.h>
#include "functions.h"
// Funciones que pueden ser usadas pora otras partes del proyecto (Para el archivo proyect2.c)
//Hola
/*Ejercicio 2 Implementación */
//Crear la esstructura strStack 
struct strChack {
    int capacity = 0;
    char array[capacity];
    char *arrayPonier = array;  // Apuntador al arreglo dinámico que almacena los elementos del stack
    int top;        // Índice del elemento superior del stack   // Capacidad máxima del stack
    //El tamaño logico de la pila N, tal que siempre cumple N<=C
};
//La estructura 
//Entonces aqui, voy a implementar los metodos 
//El mas sencillo seria el stack_create
chack_create(int capacity) {
    //No debera tener ningun prior , ya que el push se hace con realloc . 
    //Debe ser una capacidad >=3 
    if(capacity <3) return NULL; //  o que tendria que retornar , pido de nuevo el valor 
    //Despues creo el arreglo dinamicamente con malloc 
    Chack newStack = (Chack) malloc(capacity * sizeof(struct strStack));
};
//Metodo push, se implementa con realloc , ya que no tiene una estructura 
//Autoreferencial , como un nodo 
void chack_push(Chack stack, char symbol){
    if(sizeof((Chack->array)) == Chack->capacity)
    
};

//-----------------------------------------------------------------------------------------------------------

/*Ejercicio 3 implementacio*/
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