#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct{
    int vertices[MAX];
    int top;
}Stack;

void initialize(Stack*s){
    s->top=-1;
}

int isEmpty(Stack* s){
    return (s->top==-1);
}

int isFull(Stack* s){
    return (s->top==MAX-1);
}

void push(Stack*s, int ele){
    if(!isFull(s)){
        s->vertices[++s->top]=ele;
    }
    else{
        printf("Stack overflow");
    }
}

void pop(Stack*s){
    if(!isEmpty(s)){
        s->top--;
    }
    else{
        printf("Stack underflow");
    }
}

typedef struct{
    int** adjMatrix;
    int v;
}Graph;

Graph* createGraph(Graph*g){
    g->adjMatrix=(int**)malloc(g->v*sizeof(int*));
    for(int i=0;i<g->v;i++){
        g->adjMatrix[i] = (int*)calloc(g->v, sizeof(int));
    }
    return g;
}

void addEdge(Graph*g,int src,int dest){
    g->adjMatrix[src][dest]=1;

}

void dfs(Graph*g,int startVertex){
    Stack*s;
    
    int visited[MAX]={0};

    push(s,startVertex);
    visited[startVertex]=1;
    for(int i=0;i<g->v;i++){

        while(g->adjMatrix[startVertex][i]==1 && visited[i]!=1){
            push(s,i);
            printf("pushed %d",i);
            visited[i]=1;
            startVertex=i;
        }
        printf("popped %d",s->vertices[s->top]);
        pop(s);
        
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

    dfs(g,0);




return 0;

}