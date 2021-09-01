#include <stdio.h>
#define MAX 10000

void radixSort(int *a, int n) {
    int res[MAX], maxValue = 0;
    int exp = 1;

    for(int i=0; i<n; i++) {
        if(a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    while (maxValue / exp > 0) {    // 1의 자리부터 계산
        int bucket[10] = {0};
        for(int i=0; i<n;i++) {
            bucket[a[i] / exp %10]++;   // 자릿수 배열 처리
        }
        for(int i=1; i<10;i++) {
            bucket[i] += bucket[i-1];   //누적 계산
        }
        for(int i = n-1; i>=0; i--) {
            res[--bucket[a[i] / exp %10]] = a[i];   //같은 자릿수끼리는 순서를 유지
        }
        for(int i=0; i<n;i++) {
            a[i] = res[i];  // 기본 배열 갱신
        }
        exp *= 10;
    }   
}

int main() {
    int a[MAX];
    int i, n;

    printf("입력할 숫자의 개수를 입력하시오 >>\n");
    scanf("%d", &n);

    printf("%d개의 숫자를 입력하시오 (공백으로 분리) >>\n", n);
    for(i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    radixSort(a, n);
    for(i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}