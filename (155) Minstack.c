#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct StackNode {
    int value;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void pushStack(Stack* stack, int val) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->value = val;
    newNode->next = stack->top;
    stack->top = newNode;
}

void popStack(Stack* stack) {
    if (stack->top == NULL) return;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

int topStack(Stack* stack) {
    return (stack->top) ? stack->top->value : INT_MIN;
}

typedef struct {
    Stack* mainStack;
    Stack* minStack;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->mainStack = createStack();
    obj->minStack = createStack();
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    pushStack(obj->mainStack, val);
    if (obj->minStack->top == NULL || val <= topStack(obj->minStack)) {
        pushStack(obj->minStack, val);
    }
}

void minStackPop(MinStack* obj) {
    if (obj->mainStack->top == NULL) return;
    if (topStack(obj->mainStack) == topStack(obj->minStack)) {
        popStack(obj->minStack);
    }
    popStack(obj->mainStack);
}

int minStackTop(MinStack* obj) {
    return topStack(obj->mainStack);
}

int minStackGetMin(MinStack* obj) {
    return topStack(obj->minStack);
}
