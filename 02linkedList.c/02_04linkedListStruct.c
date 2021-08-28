#include <stdio.h>
#include <stdlib.h>

// single linked list

typedef struct {
    int data;
    struct Node *next;
} Node;

Node *head;

// 연결 리스트 삽입함수
// root가 head가 됨
void addFront(Node *root, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

// 연결 리스트 삭제함수
void removeFront(Node *root) {
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

// 연결 리스트 메모리 해제 함수 (head를 제외하고 할당 해제)
void freeAll(Node *root) {
    Node *iter = head->next;

    while (iter != NULL) {
        Node *next = iter->next;
        free(iter);
        iter = next;
    }
}

// 연결 리스트 전체 출력 함수
void showAll(Node *root) {
    Node *iter = head->next;

    while (iter != NULL) {
        printf("%d \n", iter->data);
        iter = iter->next;
    }
}

int main() {
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);
    showAll(head);
    freeAll(head);
}
