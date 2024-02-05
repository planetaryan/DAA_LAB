#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct{
    int arr[MAX];
    int front;
    int rear;
}Queue;

int isFull(Queue* q){
    return ((q->rear + 1) % MAX == q->front);
}

int isEmpty(Queue* q){
    return (q->rear == -1);
}

void enqueue(Queue* q,int ele){
    if(!isFull(q)){
        if(q->front==-1){
            q->front=0;
        }
        q->arr[++q->rear];
    }
}

int dequeue(Queue* q){
    if(!isEmpty(q)){
        return("%d ",q->arr[q->front--]);
    }
}

typedef struct{
    int** adjMatrix;
    int v;
}Graph;

Graph* createGraph(int numVertices){

    Graph* g = malloc(sizeof(Graph));
    g->v = numVertices;

    for(int i=0;i<g->v;i++){
        g->adjMatrix[i] = (int*)calloc(g->v, sizeof(int));
    }

    return g;

}

void addEdge(Graph*g,int src,int dest){
    g->adjMatrix[src][dest]=1;
}

void bfs(int startVertex,int numVertices){
    Queue *q;
    Graph* g=createGraph(numVertices);

    int visited[MAX]={0};
    enqueue(q,startVertex);
    visited[startVertex]=1;
    for(int i=0;i<g->v;i++){
        if(g->adjMatrix[startVertex][i]==1 && visited[startVertex]!=1){
            enqueue(q,i);
        }
        dequeue(q);

    }


}

int main(){
    Graph*g=(Graph*)malloc(sizeof(Graph));
    g->v=5;

   Graph* graph=createGraph(g);
    

    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,1);
    addEdge(graph,3,4);

    bfs(0,g->v);




return 0;

}
