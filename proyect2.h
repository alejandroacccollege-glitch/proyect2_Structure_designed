#ifndef TEST_H_
#define TEST_H_
#include "functions.h"
/* Cabecera de las implementaciones (archivo proyect2.c) 
además de las cosas que deben ser públicas para el archivo Tests.c*/ 

void createMatrix(char****, unsigned int**, char* words[], int); //Prototipo de la funcion del ejercicio 1
Bool isBalanced(char fileName[]); // Prototipo de la función del ejercicio 3
Queue createTaskQueue(char* filename); // Prototipo de la función 1 del ejercicio 4
void processTaskQueue(Queue q, char* logfilename); // Prototipo de la función 2 del ejercicio 4
#endif