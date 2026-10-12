#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int listLength(struct Node *head);
void displayList(struct Node *head);
void insertBeginning(int value, struct Node **head, struct Node **tail);
void insertEnd(int value, struct Node **head, struct Node **tail);
void insertAtPosition(int value, int position,
                      struct Node **head, struct Node **tail);
void insertMiddle(int value, struct Node **head, struct Node **tail);
void deleteBeginning(struct Node **head, struct Node **tail);
void deleteEnd(struct Node **head, struct Node **tail);
void deleteAtPosition(int position, struct Node **head, struct Node **tail);
void deleteByValue(int value, struct Node **head, struct Node **tail);
void freeList(struct Node **head, struct Node **tail);

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

int main(void)
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    insertBeginning(1, &head, &tail);
    insertEnd(2, &head, &tail);
    insertEnd(4, &head, &tail);
    insertAtPosition(0, 0, &head, &tail);
    insertAtPosition(3, 3, &head, &tail);
    insertEnd(5, &head, &tail);
    insertEnd(6, &head, &tail);
    insertEnd(7, &head, &tail);

    printf("Circular Linked List before deletion:\n");
    displayList(head);

    deleteBeginning(&head, &tail);
    deleteEnd(&head, &tail);
    deleteAtPosition(1, &head, &tail);
    deleteByValue(3, &head, &tail);

    printf("Circular Linked List after deletion:\n");
    displayList(head);

    insertMiddle(3, &head, &tail);

    printf("After inserting in the middle:\n");
    displayList(head);

    printf("Total nodes: %d\n", listLength(head));

    freeList(&head, &tail);

    return 0;
}

int listLength(struct Node *head)
{
    if (head == NULL)
        return 0;

    int count = 0;
    struct Node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
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

void insertAtPosition(int value, int position,
                      struct Node **head, struct Node **tail)
{
    int length = listLength(*head);

    if (position < 0)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 0)
    {
        insertBeginning(value, head, tail);
        return;
    }

    if (position >= length)
    {
        insertEnd(value, head, tail);
        return;
    }

    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return;

    struct Node *current = *head;

    for (int i = 0; i < position - 1; i++)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
}

void insertMiddle(int value, struct Node **head, struct Node **tail)
{
    int length = listLength(*head);

    insertAtPosition(value, length / 2, head, tail);
}

void deleteBeginning(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;

    if (*head == *tail)
    {
        *head = *tail = NULL;
    }
    else
    {
        *head = (*head)->next;
        (*tail)->next = *head;
    }

    free(temp);
}

void deleteEnd(struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
        return;
    }

    struct Node *current = *head;

    while (current->next != *tail)
        current = current->next;

    free(*tail);

    *tail = current;
    (*tail)->next = *head;
}

void deleteAtPosition(int position, struct Node **head, struct Node **tail)
{
    int length = listLength(*head);

    if (position < 0 || position >= length)
    {
        printf("Invalid deletion position!\n");
        return;
    }

    if (position == 0)
    {
        deleteBeginning(head, tail);
        return;
    }

    if (position == length - 1)
    {
        deleteEnd(head, tail);
        return;
    }

    struct Node *current = *head;

    for (int i = 0; i < position - 1; i++)
        current = current->next;

    struct Node *temp = current->next;
    current->next = temp->next;

    free(temp);
}

void deleteByValue(int value, struct Node **head, struct Node **tail)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = *head;
    int position = 0;

    do
    {
        if (current->data == value)
        {
            deleteAtPosition(position, head, tail);
            return;
        }

        current = current->next;
        position++;

    } while (current != *head);

    printf("Value %d not found.\n", value);
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
