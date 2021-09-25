#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000

// 문자열 순차 탐색

char **array;
int founded;

int main() {
    int n;
    char *word;

    printf("단어의 개수, 타겟[찾을] 단어 (띄워쓰기로 구분)>> ");
    word = malloc(sizeof(char) * LENGTH);
    scanf("%d %s", &n, word);
    array = (char**) malloc(sizeof(char*) * n);

    printf("찾을 단어를 포함한 %d개의 단어를 입력하세요>> ", n);
    for(int i=0; i<n; i++) {
        array[i] = malloc(sizeof(char) * LENGTH);
        scanf("%s", array[i]);
    }

    for(int i=0; i<n; i++) {
        if(!strcmp(array[i], word)) {
            printf("%d번째 원소입니다. \n", i+1);
            founded = 1;
        }
    }

    if(!founded) printf("원소를 찾을 수 없습니다. \n");
}