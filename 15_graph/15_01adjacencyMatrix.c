#include <stdio.h>

// 무방향 비가중치 그래프와 인접 행렬

int a[1001][1001];
int n, m;

int main() {
    printf("행과 열을 입력하시오>> ");
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}