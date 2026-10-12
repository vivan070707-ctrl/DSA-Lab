#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

void printLinkedList(struct Node *start);
void insertStart(int val, struct Node **start);
void insertEnd(int val, struct Node **start);
void insertIndex(int val, int idx, struct Node **start);
void reverseList(struct Node **start);
void freeList(struct Node *start);

int main(void)
{
    struct Node *start = NULL;

    insertStart(1, &start);
    insertEnd(2, &start);
    insertEnd(3, &start);
    insertIndex(2, 2, &start);

    printf("Original linked list: ");
    printLinkedList(start);

    reverseList(&start);

    printf("After reversing: ");
    printLinkedList(start);

    freeList(start);

    return 0;
}

void printLinkedList(struct Node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *cur = start;

    while (cur != NULL)
    {
        printf("%d", cur->val);

        if (cur->next != NULL)
            printf(" -> ");

        cur = cur->next;
    }

    printf("\n");
}

void insertStart(int val, struct Node **start)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    temp->val = val;
    temp->next = *start;
    *start = temp;
}

void insertEnd(int val, struct Node **start)
{
    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    temp->val = val;
    temp->next = NULL;

    if (*start == NULL)
    {
        *start = temp;
        return;
    }

    struct Node *cur = *start;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
}

void insertIndex(int val, int idx, struct Node **start)
{
    if (idx < 0)
    {
        printf("Invalid index.\n");
        return;
    }

    if (idx == 0)
    {
        insertStart(val, start);
        return;
    }

    struct Node *cur = *start;

    for (int i = 0; i < idx - 1 && cur != NULL; i++)
        cur = cur->next;

    if (cur == NULL)
    {
        printf("Index out of range.\n");
        return;
    }

    struct Node *temp = malloc(sizeof(struct Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    temp->val = val;
    temp->next = cur->next;
    cur->next = temp;
}

void reverseList(struct Node **start)
{
    struct Node *prev = NULL;
    struct Node *cur = *start;

    while (cur != NULL)
    {
        struct Node *next = cur->next;

        cur->next = prev;

        prev = cur;
        cur = next;
    }

    *start = prev;
}

void freeList(struct Node *start)
{
    while (start != NULL)
    {
        struct Node *temp = start;
        start = start->next;
        free(temp);
    }
}
