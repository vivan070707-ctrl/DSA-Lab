#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

struct Stack *initializeStack(void);
int isEmpty(struct Stack *s);
void pushStack(int val, struct Stack *s);
void printStack(struct Stack *s);
int popStack(struct Stack *s);
int topStack(struct Stack *s);
void freeStack(struct Stack *s);

int main(void)
{
    struct Stack *myStack = initializeStack();

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

struct Stack *initializeStack(void)
{
    struct Stack *newStack = malloc(sizeof(struct Stack));

    if (newStack == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newStack->top = NULL;

    return newStack;
}

int isEmpty(struct Stack *s)
{
    return s->top == NULL;
}

void pushStack(int val, struct Stack *s)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    temp->val = val;
    temp->next = s->top;
    s->top = temp;
}

int popStack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    struct Node *temp = s->top;
    int val = temp->val;

    s->top = temp->next;
    free(temp);

    return val;
}

int topStack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return -1;
    }

    return s->top->val;
}

void printStack(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top to bottom): ");

    struct Node *cur = s->top;

    while (cur != NULL)
    {
        printf("%d", cur->val);

        if (cur->next != NULL)
            printf(" -> ");

        cur = cur->next;
    }

    printf("\n");
}

void freeStack(struct Stack *s)
{
    while (s->top != NULL)
    {
        struct Node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }

    free(s);
}
