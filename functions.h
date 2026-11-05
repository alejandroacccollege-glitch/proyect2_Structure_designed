#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct strNode {
    char pairedDelimiter;
    struct strNode *prior;
};

struct strStack {
    Node top;
    int size;
};

typedef struct strNode *Node;
typedef struct strStack *Stack;
typedef enum {False, True} Bool;
void push(Stack, char);
char pop(Stack);

#endif