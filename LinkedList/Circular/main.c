#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }

    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;

    return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        return head;
    }

    struct Node *newNode = createNode(data);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;

    return head;
}

struct Node *insertBefore(struct Node *head, struct Node *nextNode, int data)
{
    if (nextNode == NULL)
    {
        return head;
    }

    struct Node *newNode = createNode(data);
    newNode->prev = nextNode->prev;
    newNode->next = nextNode;
    nextNode->prev->next = newNode;
    nextNode->prev = newNode;

    if (nextNode == head)
    {
        head = newNode;
    }

    return head;
}

struct Node *deleteNode(struct Node *head, struct Node *delNode)
{
    if (head == NULL || delNode == NULL)
    {
        return head;
    }

    if (head == delNode && head->next == head)
    {
        free(delNode);
        return NULL;
    }

    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;

    if (delNode == head)
    {
        head = delNode->next;
    }

    free(delNode);

    return head;
}

void printForward(struct Node *head)
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
    printf("... (Loop)\n");
}

void printBackward(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head->prev;

    while (current != head->prev) {
        printf("%d -> ", current->data);
        current = current->prev;
    }

    printf("... (Loop)\n");

}