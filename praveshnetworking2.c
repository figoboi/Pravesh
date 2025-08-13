#include <stdio.h>
#define MAX 3

void main() {
    int a[MAX][MAX];
    int visited[MAX] = { -1, -1, -1 }, cost[MAX], b[MAX][MAX], path[MAX] = { 0, 0, 0 };
    int i, j, c = 0, k, src = 0, temp, flag = 0, m, p, srcTemp, ctr = 0, strace[MAX] = { 0, 0, 0 }, temp1, temp2;

    printf("\nEnter the matrix: ");
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    cost[src] = 0;
    for (p = 0; p < MAX; p++) {
        visited[c] = src;
        for (k = 0; k < MAX; k++) {
            for (m = 0; m < MAX; m++) {
                if (k == visited[m]) {
                    b[c][k] = 999;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                flag = 0;
                continue;
            }
            if (c > 0) {
                if (b[c - 1][k] > a[src][k] + cost[src]) {
                    b[c][k] = a[src][k] + cost[src];
                } else {
                    b[c][k] = b[c - 1][k];
                }
            } else {
                b[c][k] = a[src][k] + cost[src];
            }
        }

        temp = b[c][1];
        srcTemp = 1;
        for (k = 0; k < MAX; k++) {
            for (m = 0; m < MAX; m++) {
                if (k == visited[m]) {
                    flag = 1;
                    break;
                }
            }
            if (b[c][k] < temp && flag != 1) {
                temp = b[c][k];
                srcTemp = k;
            }
            flag = 0;
        }

        for (k = 0; k < MAX; k++) {
            printf("%d ", b[c][k]);
        }
        printf("----->%d", c);
        printf("\n");

        src = srcTemp;
        strace[c + 1] = src;
        cost[src] = temp;
        c++;
        visited[c] = src;
    }

    printf("shortest distance from source node 0 to...\n");
    for (i = 0; i < MAX; i++) {
        printf("%d is %d \n", i, cost[i]);
    }

    for (i = MAX - 2; i >= 0; i--) {
        j = i + 1;
        temp1 = b[i - 1][strace[j]];
        temp2 = b[i - 1][strace[i]];
        path[ctr] = strace[i];
        if (temp1 != temp2) {
            i--;
        }
        ctr++;
    }

    printf("\n");
    for (j = 0; j < MAX - 1; j++) {
        if (j == MAX - 2) {
            printf("%d", path[j]);
        } else {
            printf("%d->", path[j]);
        }
    }
}