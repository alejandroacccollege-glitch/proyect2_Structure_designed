#include <stdio.h>
#include <stdlib.h>
#include "proyect2.h"
// Ejercicio 1

void createMatrix(char**** matrix, unsigned int** counts, char* words[], int numWords) {
    
    *counts = (unsigned int*) calloc(26, sizeof(unsigned int));

    
    for (int i = 0; i < numWords; i++) {
        int row = words[i][0] - 'a';
        (*counts)[row]++;
    }

    
    *matrix = (char***) malloc(26 * sizeof(char**));

    
    for (int i = 0; i < 26; i++) {
        if ((*counts)[i] > 0) {
            (*matrix)[i] = (char**) malloc((*counts)[i] * sizeof(char*));
        } else {
            (*matrix)[i] = NULL;
        }
    }

    
    int pos[26] = {0};

    
    for (int i = 0; i < numWords; i++) {
        int row = words[i][0] - 'a';
        int col = pos[row];
        (*matrix)[row][col] = words[i];
        pos[row]++;
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

    Bool balanced = True;
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
                {
                balanced = False; // Primero, si la pila está vacía marca falso ya que no hay con que verificar
                break;
            } // Primero, si la pila está vacía devuelve falso ya que no hay con que verificar
            
                char stackChar = signs->top->pairedDelimiter; /* Se revisa el delimitador que se encuentra
                almacenado en el Stack */
            switch (currentChar)
            { /*En cada caso si el delimitador (de cierre) actual no tiene su signo de apertura almacenado en 
                el Stack devuelve directamente falso ya que con uno que no tenga su cierre ya no está balanceado, 
                si no se cumple la condición anterior se saca el delimitador de apertura, es decir va vaciando 
                el Stack */
            case '>':
                if (stackChar != '<')
                    balanced = False;
                else pop(signs);
                break;
            case '}':
                if (stackChar != '{')
                    balanced = False;
                else pop(signs);
                break;
            case ')':
                if (stackChar != '(')
                    balanced = False;
                else pop(signs);
                break;
            case ']':
                if (stackChar != '[')
                   balanced = False;
                else pop(signs);
                break;
            }
        }
        currentChar = fgetc(fileOpened); /*Después de hacer las verificaciones anteriores, se pasa al 
        siguiente carácter para volver a empezar el while*/ 
    }
    fclose(fileOpened); // Cierra el archivo
    Bool result = False;
    
    if (balanced == True && signs->size == 0){ 
        result = True;} /* Al vaciarse conforme encuantra pares, al final si encuentra 
    un cierre para cada cada apertura termina el stack vacío, por lo que será verdadero el hecho de
    estar balanceado */
    else{
        while (signs->top != NULL){
            pop(signs);
        }
    }
    free(signs); //Libera el Stack usado para la revisión
    return result; /* Caso contrario al anterior, devuelve falso ya que se quedaron aquellas aperturas 
    que no encintraron cierre */
}
//-------------------------------------------------
// Ejercicio 4
Queue createTaskQueue(char* filename)
{
    FILE *fileOpened = fopen(filename, "rb"); // Abre el archivo binario existente en modo lectura binaria

    if (!fileOpened)
        return NULL; /* Si no pudo abrir el archivo binario porque no existe en la ruta,
        devuelve NULL directamente */

    Queue taskQueue = queue_create(); /* Crea la cola vacía donde se irán formando los pares
    leídos en el mismo orden de lectura */

    unsigned short tempId;
    unsigned short tempDuration;

    /* Mientras fread logre leer exitosamente ambos enteros sin signo de 16 bits (Id y Duration)
    del archivo binario, se crea la tarea en memoria dinámica y se forma en la cola */
    while (fread(&tempId, sizeof(unsigned short), 1, fileOpened) == 1 &&
           fread(&tempDuration, sizeof(unsigned short), 1, fileOpened) == 1)
    {
        Task currentTask = (Task) malloc(sizeof(struct strTask));
        currentTask->id = tempId;
        currentTask->duration = tempDuration;

        queue_offer(taskQueue, currentTask); // Inserta el par leído al final de la cola
    }

    fclose(fileOpened); // Cierra el archivo binario una vez terminada la lectura
    return taskQueue;   // Devuelve la cola con todas las tareas cargadas
}

void processTaskQueue(Queue q, char* logfilename)
{
    if (q == NULL) return; // Verifica que la cola exista antes de procesarla

    FILE *logFile = fopen(logfilename, "w"); // Abre o crea el archivo de texto para guardar el registro
    if (!logFile) return;

    int stepCounter = 1; // Contador para numerar cada renglón procesado en el archivo Log.txt

    while (!queue_isEmpty(q)) // Mientras aún existan tareas formadas en la cola esperando procesador
    {
        Task activeTask = queue_poll(q); /* Extrae la tarea que está al frente de la cola para
        darle su turno en el procesador */

        activeTask->duration--; // Consume 1 ciclo de reloj de la tarea activa

        /* Escribe en un nuevo renglón del archivo de texto el número de paso, el Id de la tarea
        activa y cuántos pasos le quedan por acabar */
        fprintf(logFile, "%d) Active task: %hu, remaining steps: %hu\n",
                stepCounter, activeTask->id, activeTask->duration);
        stepCounter++;

        if (activeTask->duration > 0)
        {
            /* Si aún le quedan ciclos de reloj pendientes, la tarea se vuelve a formar
            al final de la cola para esperar su siguiente turno */
            queue_offer(q, activeTask);
        }
        else
        {
            /* Si los pasos restantes llegaron a 0, la tarea ya terminó su ejecución y se libera
            su memoria dinámica para no dejar fugas */
            free(activeTask);
        }
    }

    fclose(logFile); // Cierra el archivo de texto Log.txt con los 95 renglones generados
}