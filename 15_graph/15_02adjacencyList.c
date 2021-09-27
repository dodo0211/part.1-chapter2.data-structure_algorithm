#include <stdio.h>
#include <stdlib.h>

// 방향 가중치 그래프와 인접 리스트

// 연결 리스트 구조체 만들기
typedef struct {
    int index;
    int distance;   // 가중치
    struct Node *next;
} Node;

// 연결 리스트 삽입 함수
void addFront(Node *root, int index, int distance) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->distance = distance;
    node->next = root->next;
    root->next = node;
}

// 연결 리스트 출력 함수
void showAll(Node *root) {
    Node *cur = root->next;

    while(cur != NULL) {
        printf("%d (거리: %d) ", cur->index, cur->distance);
        cur = cur->next;
    }
}

// 연결 리스트 사용
int main() {
    int n, m;
    printf("노드의 개수와 입력 받을 개수를 입력하시오>> ");
    scanf("%d %d", &n, &m);
    Node** a = (Node**)malloc(sizeof(Node*) * (n+1));

    // 노드 초기화  
    for(int i=1; i<=n; i++) {
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }

    // 몇 개 추가?
    for(int i=0; i<m; i++) {
        int x, y, distance;
        scanf("%d %d %d", &x, &y, &distance);
        addFront(a[x], y, distance);
    }

    for(int i=1; i<=n; i++) {
        printf("원소 [%d]: ", i);
        showAll(a[i]);
        printf("\n");
    }
}