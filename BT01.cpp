#include<stdio.h>
#define V 100  
int visited[V];
int graph[V][V]; 
typedef struct Queue {
    int item[V];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == V - 1) {
        printf("Hang doi day!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->item[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong\n");
        return -1;
    }
    int value = q->item[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void BFS(int start, int n) {
    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enqueue(&q, start);
    visited[start] = 1;

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int v;
    int e;
    printf("Nhap so dinh: ");
    scanf("%d", &v);
    printf("Nhap so canh: ");
    scanf("%d", &e);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    int start;
    int u, w;
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < v && w >= 0 && w < v) {
            graph[u][w] = 1;
            graph[w][u] = 1;
        } 
    }

    printf("Nhap dinh bat dau: ");
    scanf("%d", &start);
    printf("Ket qua BFS: ");
    BFS(start, v);
    return 0;
}

