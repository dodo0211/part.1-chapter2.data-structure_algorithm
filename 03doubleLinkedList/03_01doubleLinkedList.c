#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;    
} Node;

Node *head, *tail;

// 오름차순으로 삽입되도록
void insert(int data) {
    // 메모리 할당
    Node* node = (Node*)malloc(sizeof(Node));
    // data값 초기화
    node->data = data;
    // node가 들어갈 위치를 정함
    Node* cur;
    cur = head->next;

    // 오름차순 유지
    while(cur->data < data && cur !=tail) {
        cur = cur->next;
    }

    // 삽입할 원소의 위치에서 prev 위치를 잡아준다.
    Node* prev = cur->prev;
    prev->next = node;
    node->prev = prev;
    cur->prev = node;
    node->next = cur;
}

// head에서 가장 가까운 원소를 지움
void removeFront() {
    Node* node = head->next;
    head->next = node->next;
    Node* next = node->next;
    next->prev = head;
    free(node);
}

void show() {
    Node* iter = head->next;

    while(iter != tail) {
        printf("%d \n", iter->data);
        iter = iter->next;
    }
}

int main() {
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));

    // 끝까지 도착했는지를 null이 아닌 tail로 알기 때문에
    head->next = tail;
    head->prev = head;
    tail->next = tail;
    tail->prev = head;

    insert(2);
    insert(1);
    insert(3);
    insert(9);
    insert(7);

    removeFront();
    show();
}