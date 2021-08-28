#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
// 스택의 최상단을 의미하는 변수 (스택의 입구)
int top = -1;

// 스택 삽입 함수
void push(int data) {
    if(top == SIZE -1) {
        printf("스택 오버플로우가 발생했습니다. \n");
        return;
    }
    // index[0]부터 차곡차곡 들어감
    stack[++top] = data;
}

// 스택 추출 함수
int pop() {
    if(top == -1) {
        printf("스택 언더플로우가 발생했습니다. \n");
        return -INF;
    }
    return stack[top--];
}

// 스택 전체 출력 함수
void show() {
    printf("--- 스택의 최상단 --- \n");

    for(int i = top; i>=0; i--) {
        printf("%d \n", stack[i]);
    }
    printf("--- 스택의 최하단 --- \n");
}

int main() {
    push(7);
    push(5);
    push(4);
    pop();
    push(6);
    pop();
    show();
}