#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void insertBeginning(int value, struct Node **head, struct Node **tail)
{
    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    if (*head == NULL)
    {
        *head = *tail = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = *head;
    (*tail)->next = newNode;
    *head = newNode;
}

void insertEnd(int value, struct Node **head, struct Node **tail)
{
    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    if (*head == NULL)
    {
        *head = *tail = newNode;
        newNode->next = newNode;
        return;
    }

    newNode->next = *head;
    (*tail)->next = newNode;
    *tail = newNode;
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(back to head)\n");
}

void reverseCircularList(struct Node **head, struct Node **tail)
{
    if (*head == NULL || *head == *tail)
        return;

    struct Node *previous = *tail;
    struct Node *current = *head;
    struct Node *oldHead = *head;

    do
    {
        struct Node *nextNode = current->next;

        current->next = previous;
        previous = current;
        current = nextNode;

    } while (current != oldHead);

    *tail = oldHead;
    *head = previous;
}

void freeList(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
        return;

    struct Node *current = (*head)->next;

    while (current != *head)
    {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(*head);

    *head = NULL;
    *tail = NULL;
}

int main(void)
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    insertBeginning(1, &head, &tail);
    insertEnd(2, &head, &tail);
    insertEnd(3, &head, &tail);
    insertEnd(4, &head, &tail);

    printf("Original Circular Linked List:\n");
    displayList(head);

    reverseCircularList(&head, &tail);

    printf("Reversed Circular Linked List:\n");
    displayList(head);

    freeList(&head, &tail);

    return 0;
}
