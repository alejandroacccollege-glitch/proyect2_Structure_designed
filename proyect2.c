#include <stdio.h>


// Ejercicio 3
#define BUFFER_SIZE 40

typedef enum {False, True} Bool;

struct strNode {
    char pairedDelimiter;
    struct strNode *prior;
};

typedef struct strNode *Node;

struct strStack {
    Node top;
    int size;
};

typedef struct strStack *Stack;

Bool isBalanced (char filename[]){
    char buffer[BUFFER_SIZE];
    
    FILE *fileToOpen = fopen(filename, "r");
    if (!fileToOpen) return False;

    Stack signs = (Stack) malloc (sizeof(struct strStack));
    signs -> top = NULL;
    signs -> size = 0;
    
    char *readChar = fgets(buffer, BUFFER_SIZE, fileToOpen);
    
    while (readChar){
        
    }
}

int main(){
    
    return 0;
}