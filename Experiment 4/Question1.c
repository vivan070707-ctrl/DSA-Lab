#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtBeginning(int value, struct Node *head);
struct Node *insertAtEnd(int value, struct Node *head);
struct Node *insertAtPosition(int value, int position, struct Node *head);
struct Node *insertAtMiddle(int value, struct Node *head);
struct Node *deleteByValue(int value, struct Node *head);
struct Node *deleteAtPosition(int position, struct Node *head);
void displayList(struct Node *head);
void freeList(struct Node *head);

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

    head = insertAtEnd(20, head);
    head = insertAtBeginning(10, head);
    head = insertAtEnd(40, head);
    head = insertAtPosition(50, 10, head);
    head = insertAtMiddle(30, head);

    printf("Original Linked List:\n");
    displayList(head);

    head = deleteAtPosition(3, head);
    head = deleteByValue(50, head);
    head = deleteAtPosition(10, head);

    printf("Updated Linked List:\n");
    displayList(head);

    freeList(head);

    return 0;
}

struct Node *insertAtBeginning(int value, struct Node *head)
{
    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return head;

    newNode->next = head;

    return newNode;
}

struct Node *insertAtEnd(int value, struct Node *head)
{
    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return head;

    if (head == NULL)
        return newNode;

    struct Node *current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;

    return head;
}

struct Node *insertAtPosition(int value, int position, struct Node *head)
{
    if (position < 0)
    {
        printf("Invalid position!\n");
        return head;
    }

    if (position == 0)
        return insertAtBeginning(value, head);

    struct Node *current = head;

    for (int i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position out of range. Inserting at the end.\n");
        return insertAtEnd(value, head);
    }

    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return head;

    newNode->next = current->next;
    current->next = newNode;

    return head;
}

struct Node *insertAtMiddle(int value, struct Node *head)
{
    if (head == NULL)
        return insertAtBeginning(value, head);

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *newNode = createNode(value);

    if (newNode == NULL)
        return head;

    newNode->next = slow->next;
    slow->next = newNode;

    return head;
}

struct Node *deleteAtPosition(int position, struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return NULL;
    }

    if (position < 0)
    {
        printf("Invalid position!\n");
        return head;
    }

    if (position == 0)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    struct Node *current = head;

    for (int i = 0; i < position - 1 && current->next != NULL; i++)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Position out of range. Deletion failed.\n");
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;

    free(temp);

    return head;
}

struct Node *deleteByValue(int value, struct Node *head)
{
    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return NULL;
    }

    if (head->data == value)
        return deleteAtPosition(0, head);

    struct Node *current = head;

    while (current->next != NULL && current->next->data != value)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        printf("Value %d not found.\n", value);
        return head;
    }

    struct Node *temp = current->next;
    current->next = temp->next;

    free(temp);

    return head;
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    while (current != NULL)
    {
        printf("%d", current->data);

        if (current->next != NULL)
            printf(" -> ");

        current = current->next;
    }

    printf(" -> NULL\n");
}

void freeList(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}
