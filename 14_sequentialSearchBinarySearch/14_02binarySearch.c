#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];
int founded = 0;

int search(int start, int end, int target) {
    if(start > end) return -9999;
    
    int mid = (start + end) / 2;

    if(a[mid] == target) {
        return mid;
    } else if(a[mid] > target) {
        return search(start, mid-1, target);
    } else {
        return search(mid+1, end, target);
    }
}

int main() {
    int n, target;
    printf("입력할 자연수의 개수, 타겟[찾을] 숫자 (띄어쓰기로 구분)>> ");
    scanf("%d %d", &n, &target);

    printf("타겟 숫자를 포함하여 %d개의 자연수를 입력하시오", n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int result = search(0, n-1, target);

    if(result != -9999) {
        printf("%d번째 원소입니다. \n", result+1);
    }else {
        printf("원소를 찾을 수 없습니다. \n");
    }
}