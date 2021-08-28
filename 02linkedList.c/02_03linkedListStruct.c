#include <stdio.h>
#include <stdlib.h>

// single linked list

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

int main() {
    head = (Node*)malloc(sizeof(Node));
    Node *node1 = (Node*) malloc(sizeof(Node));
    node1 -> data = 1;
    Node *node2 = (Node*) malloc(sizeof(Node));
    node2->data = 2;
    head->next = node1;
    node1->next = node2;
    node2->next = NULL;
    Node *itr = head->next;

    while (itr != NULL) {
        printf("%d \n", itr->data);
        itr = itr->next;
    }
}
