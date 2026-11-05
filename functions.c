#include <stdlib.h>
#include "functions.h"
// Funciones que pueden ser usadas pora otras partes del proyecto (Para el archivo proyect2.c)
//Hola
/*Ejercicio 2 Implementación */
/*Ejercicio 2 Implementación */

//Crear la esstructura strStack
struct strChack {

    char * array; //Apuntador al arreglo ,de chars
    int Capacidad; //Es la capacidad c total
    //C es el numeor total de casilas , con malloc
    int N; //Es el tamaño logico , osea el numero
    //Numero de caracterres que se han metido en la pila

};
//Ejemplo de C y N
//C=[[][][]] 3 casillas
//N= [[1][][]] 1 elemento N= 1, a eso refiere lo logico
//La estructura
//Entonces aqui, voy a implementar los metodos
//El mas sencillo seria el stack_create
Chack chack_create(int capacity) {
    //No debera tener ningun prior , ya que el push se hace con realloc .
    //Debe ser una capacidad >=3
    if(capacity <3) return NULL; //  o que tendria que retornar , pido de nuevo el valor
    //Despues creo el arreglo dinamicamente con malloc
    //El apuntador es el que lo contiene
    Chack chack= (Chack)malloc(sizeof(struct strChack));
    //Reservar la memoria en el apuntador
    chack->array=(char*)malloc(capacity*sizeof(char));
    //Se inicializan los valores
    chack->Capacidad=capacity;  //Esto si fueron >=3
    chack->N=0; //Se inician con cero caracteres
    return chack;
};

//Metodo push, se implementa con realloc , ya que no tiene una estructura
//Autoreferencial , como un nodo

void chack_push(Chack chack , char symbol){
    //Si ya se lleno (C capacidad== N ).
    if(chack->N==chack->Capacidad){
        chack->Capacidad=chack->Capacidad*2;
        //se duplica el tamaño con realloc , y symbol lo agregeo?
        chack->array=(char*)realloc(chack->array,chack->Capacidad*sizeof(char )); //Ya se agrega el doble
    }
    //Agregar el caracter en el tope , entrando en ese indice
    chack->array[chack->N]=symbol; //Se agrega al bloque en el indice N , el ultimo elemento
    chack->N++;
};

//Ahora el pop solo va hacia el caracter en el tope , si la pila esta vacia devuelve 0
//La extraccion es solamente logica
char chack_pop(Chack chack ){
    if(chack->N==0)return 0; //Creo que se puede retornar False
    //N-- , numoer logico pero no fisico
    chack->N--;
    return chack->array[chack->N];
};

//Chack isempty, tipo BOOL
Bool chack_isEmpty(Chack chack){
    if(chack->N==0)return True;
    return False;
};

//El top si la pila esta vacia devuelve 0
char chack_top(Chack chack){
    if (chack_isEmpty(chack)) {
        return 0;
    }

    return chack->array[chack->N - 1];
}

//size , solo retorna el tamaño N , no la capacidad creo
int chack_size(Chack chack){
    return chack->N;
};

void chack_print(Chack k){
    //  Si la pila está vacía o el apuntador es nulo
    if (chack_isEmpty(k)) {
        printf("Empty chack\n");
        return;
    }

    //  Imprimir el encabezado con el corchete de apertura
    printf("Chack: [");

    //  Recorrer desde el tope (N - 1) hasta el fondo (0)
    for (int i = k->N - 1; i >= 0; i--) {
        printf("%c", k->array[i]);
    }

    //  Cerrar corchete y salto de línea
    printf("]\n");
};

//Chack clear realiza el vaciado lógico de la pila ,
void chack_clear(Chack chack){
    if(chack==NULL)return;
    chack->N=0;
};

//-----------------------------------------------------------------------------------------------------------

//Ejercicio 3 implementacion
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