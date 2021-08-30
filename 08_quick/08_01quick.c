#include <stdio.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end) {
    if(start >= end) return;
    int key = start, i = start + 1, j = end, temp;

    while (i <= j) {    // 엇갈릴 때까지 반복
        while( i <= end && a[i] <= a[key]) i++;
        while(j > start && a[j] >= a[key]) j--;

        if(i > j) swap(&a[key], &a[j]);
        else swap(&a[i], &a[j]);
    }
    quickSort(start, j - 1);
    quickSort(j + 1, end);
}

int main() {
    int n;
    printf("입력할 숫자의 개수는? >> \n");
    scanf("%d", &n);

    printf("%d개의 숫자를 입력하세요 (공백으로 분리)>> \n", n);
    for(int i = 0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(0, n-1);

    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}