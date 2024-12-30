#include<stdio.h>
#define V 52
int visited[V];
int graph[V][V]; 
void DFS(int v,int n){
    printf("%d ",v);
    visited[v] = 1;
    for(int i=0;i<n;i++){
        if(visited[i] == 0 && graph[v][i] == 1){
            DFS(i,n);
        }
    }
}
int isConnected(int n) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            return 0;
        }
    }
    return 1; 
}

int main(){
    int n;
    int start;
    int u,v,edges;
    printf("NHap vao so dinh: ");
    scanf("%d",&n);
    printf("Nhap vao so canh: ");
    scanf("%d",&edges);
    printf("Nhap cac canh (dinh u v ): ");
    for(int i=0;i<edges;i++){
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    printf("Nhap so dinh bat dau duyet: ");
    scanf("%d",&start);
    DFS(start,n);
    return 0;

}
