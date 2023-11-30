#include <stdio.h>

int max[10][10], allocation[10][10], need[10][10];
int avail[10];
int n, m;

void readmatrix(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
}

void display(int matrix[10][10]) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\n p%d", i);
        for (j = 0; j < m; j++) {
            printf("%d", matrix[i][j]);
        }
    }
}

void cal_need() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void banker() {
    int i, j, k = 0, flag;
    int fin[10], safe[10];
    for (i = 0; i < n; i++) {
        fin[i] = 0;
    }
    for (i = 0; i < n; i++) {
        flag = 0;
        if (fin[i] == 0) {
            for (j = 0; j < m; j++) {
                if (need[i][j] > avail[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                fin[i] = 1;
                safe[k] = i;
                k++;
                for (j = 0; j < m; j++)
                    avail[j] += allocation[i][j];
                i = -1;
            }
        }
    }
    flag = 0;
    for (i = 0; i < n; i++) {
        if (fin[i] == 0) {
            printf("The system is in deadlock");
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("The system is in a safe state \n Safe sequence: ");
        for (i = 0; i < n; i++) {
            printf("p%d ", safe[i]);
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    printf("Enter the allocation matrix:\n");
    readmatrix(allocation);
    printf("Enter the maximum matrix:\n");
    readmatrix(max);
    printf("Enter the available resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    cal_need();
    banker();

    return 0;
}
