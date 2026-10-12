#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *stack;
    int top;
    int size;
};

struct Stack *initializeStack(int n);
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void pushStack(int val, struct Stack *s);
void printStack(struct Stack *s);
int popStack(struct Stack *s);
int topStack(struct Stack *s);
void freeStack(struct Stack *s);

int main(void)
{
    struct Stack *myStack = initializeStack(5);

    pushStack(1, myStack);
    pushStack(2, myStack);
    pushStack(3, myStack);

    printStack(myStack);

    printf("Popped: %d\n", popStack(myStack));
    printf("Top: %d\n", topStack(myStack));
    printf("Popped: %d\n", popStack(myStack));

    printStack(myStack);

    freeStack(myStack);

    return 0;
}

struct Stack *initializeStack(int n)
{
    if (n <= 0)
    {
        printf("Invalid stack size.\n");
        exit(EXIT_FAILURE);
    }

    struct Stack *newStack = malloc(sizeof(struct Stack));

    if (newStack == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newStack->stack = malloc(n * sizeof(int));

    if (newStack->stack == NULL)
    {
        printf("Memory allocation failed.\n");
        free(newStack);
        exit(EXIT_FAILURE);
    }

    newStack->top = -1;
    newStack->size = n;

    return newStack;
}

int isFull(struct Stack *s)
{
    return s->top == s->size - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void pushStack(int val, struct Stack *s)
{
    if (isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }

    s->top++;
    s->stack[s->top] = val;
}

int popStack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    int val = s->stack[s->top];
    s->top--;

    return val;
}

int topStack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }

    return s->stack[s->top];
}

void printStack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (bottom to top): ");

    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->stack[i]);

    printf("\n");
}

void freeStack(struct Stack *s)
{
    if (s != NULL)
    {
        free(s->stack);
        free(s);
    }
}
