#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data, top, capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void pushStack(Stack* stack, int x) {
    stack->data[++stack->top] = x;
}

int popStack(Stack* stack) {
    return stack->data[stack->top--];
}

int peekStack(Stack* stack) {
    return stack->data[stack->top];
}

bool isEmptyStack(Stack* stack) {
    return stack->top == -1;
}

typedef struct {
    Stack *s1, *s2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->s1 = createStack(100);
    q->s2 = createStack(100);
    return q;
}

void myQueuePush(MyQueue* q, int x) {
    pushStack(q->s1, x);
}

int myQueuePop(MyQueue* q) {
    if (isEmptyStack(q->s2)) while (!isEmptyStack(q->s1)) pushStack(q->s2, popStack(q->s1));
    return popStack(q->s2);
}

int myQueuePeek(MyQueue* q) {
    if (isEmptyStack(q->s2)) while (!isEmptyStack(q->s1)) pushStack(q->s2, popStack(q->s1));
    return peekStack(q->s2);
}

bool myQueueEmpty(MyQueue* q) {
    return isEmptyStack(q->s1) && isEmptyStack(q->s2);
}

void myQueueFree(MyQueue* q) {
    free(q->s1->data); free(q->s1); free(q->s2->data); free(q->s2); free(q);
}
