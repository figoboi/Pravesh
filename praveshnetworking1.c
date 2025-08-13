#include<stdio.h> 

void main()
{
    int a[5][5] = {0, 7, 3, 999, 999, 7, 0, 1, 2, 6, 3, 1, 0, 2, 999, 999, 2, 2, 0, 4, 999, 6, 999, 4, 0};
    int visited[5] = {-1, -1, -1, -1, -1}, cost[5], b[5][5];
    int i, j, c = 0, k, src = 0, temp, flag = 0, m, p, srctemp;

    cost[src] = 0;
    for (p = 0; p < 5; p++)
    {
        for (k = 0; k < 5; k++)
        {
            for (m = 0; m < 5; m++)
            {
                if (k == visited[m])
                {
                    b[c][k] = 999;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                flag = 0;
                continue;
            }
            if (c > 0)
            {
                if (b[c - 1][k] > a[src][k] + cost[src])
                {
                    b[c][k] = a[src][k] + cost[src];
                }
                else
                {
                    b[c][k] = b[c - 1][k];
                }
            }
            else
            {
                b[c][k] = a[src][k] + cost[src];
            }
        }
        visited[c] = src;
        temp = b[c][1];
        srctemp = 1;
        for (k = 0; k < 5; k++)
        {
            for (m = 0; m < 5; m++)
            {
                if (k == visited[m])
                {
                    flag = 1;
                    break;
                }
            }
            if (b[c][k] < temp && flag != 1)
            {
                temp = b[c][k];
                srctemp = k;
            }
            flag = 0;
        }
        for (k = 0; k < 5; k++)
        {
            printf("%d", b[c][k]);
        }
        printf("\n");
        src = srctemp;
        cost[src] = temp;
        c++;
    }
    printf("shortest distance from source node0to...\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d is = %d \n", i, cost[i]);
    }
}