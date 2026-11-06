#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/* Cabecera de las implementacione (archivo functions.c) 
además de las cosas que deben ser públicas para el archivo proyect2.c*/ 
// Funciones para ejercicio 2 (Chack.h hipoteticamennte )
//Entonces primeor empiezo definiendo 
//el apuntador a la estructura tipo struct strstack 
typedef enum {False, True} Bool;
typedef struct strChack* Chack; 

//Metodos de la estructura 
//Seran tipo stack , por lo tanto no ucapos un type para casteo 
Chack chack_create(int);
void chack_push(Chack, char);
//El push sera con realloc , entonces la diferencia es que no se va a crear un nodo 
//La diferencia  qes que n tendre que actualizar el top, recuperando el dato en memorua fisica 
//al parecer sera todo logico esa es mi duda  
char chack_pop(Chack);
char chack_top(Chack);
Bool chack_isEmpty(Chack);

void chack_clear(Chack);
int chack_size(Chack); 
void chack_print(Chack); 
//Estos metodos son equivalentes , a los trabajados 
//En los ejercicios o estructuras anteriormente como el stack 
//Solo que estos no contienen un ndodo 
//Se van agregar con malllo
//--------------------------------------------------------------------------------------------

// Funciones para ejercicio 3
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
void push(Stack, char); // Prototipo de la implementación "push" que esta en (functions.c)
char pop(Stack); // Prototipo de la implementación "pop" que esta en (functions.c)
//--------------------------------------------------------------------------------------------

// Funciones para ejercicio 4
struct strTask {
    unsigned short id;
    unsigned short duration;
}; // Estructura que almacena el par <Task-Id, Duration> de 16 bits sin signo
typedef struct strTask *Task; // Apuntador a la estructura de cada tarea

struct strQueueNode {
    Task taskData;
    struct strQueueNode *next;
}; // Crea una estructura de lo que tiene un nodo de la cola
typedef struct strQueueNode *QueueNode; // Apunta a la estructura nodo para la cola

struct strQueue {
    QueueNode front;
    QueueNode rear;
    int size;
}; // Crea una estructura de lo que tiene una Queue (frente, final y tamaño)
typedef struct strQueue *Queue; // Apunta a la estructura Queue para crear colas

Queue queue_create(); // Prototipo para inicializar la cola en (functions.c)
int queue_size(Queue); // Prototipo para obtener el tamaño de la cola en (functions.c)
Bool queue_isEmpty(Queue); // Prototipo para verificar si la cola está vacía en (functions.c)
void queue_offer(Queue, Task); // Prototipo para formar una tarea al final de la cola en (functions.c)
Task queue_poll(Queue); // Prototipo para extraer la tarea al frente de la cola en (functions.c)
void queue_destroy(Queue); // Prototipo para liberar la memoria restante de la cola en (functions.c)
#endif