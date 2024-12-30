#include<stdio.h>
#define V 5
int visited[V];
int grap[V][V];

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && grap[v][i]) {
            DFS(i);
        }
    }
}

void printMatrix(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int v, e;
    printf("Nhap so dinh (toi da %d): ", V);
    scanf("%d", &v);
    if (v > V) {
        printf("So dinh vuot qua gioi han cho phep (%d)\n", V);
        return -1;
    }
    printf("Nhap so canh: ");
    scanf("%d", &e);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            grap[i][j] = 0;
        }
        visited[i] = 0;
    }
    int u, v2;
    for (int i = 0; i < e; i++) {
        printf("Nhap canh thu %d (u v): ", i + 1);
        scanf("%d %d", &u, &v2);
        grap[u][v2] = 1;
        grap[v2][u] = 1;
    }
    printf("Ma tran ke:\n");
    printMatrix(grap);

    int start;
    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);

    printf("DFS bat dau tu dinh %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}

