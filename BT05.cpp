#include <stdio.h>
#define V 52

int graph[V][V]; 
int visited[V];   

int DFS(int v, int parent, int n) {
    visited[v] = 1; 
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {  
            if (!visited[i]) {  
                if (DFS(i, v, n)) {  
                    return 1;
                }
            } else if (i != parent) { 
                return 1;
            }
        }
    }
    return 0;  
}

int kiemtra(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (DFS(i, -1, n)) {  
                return 1;  
            }
        }
    }
    return 0; 
}

int main() {
    int n, edges, u, v;
    printf("Nhap vao so dinh: ");
    scanf("%d", &n);
    printf("Nhap vao so canh: ");
    scanf("%d", &edges);
    printf("Nhap cac canh (dinh u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;  
    }
    if (kiemtra(n)) {
        printf("Do thi co chu trinh\n");
    } else {
        printf("Do thi khong co chu trinh\n");
    }

    return 0;
}

