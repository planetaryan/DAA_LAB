
// Adjascency List representation in C

#include <stdio.h>
#include <stdlib.h>
#define V 4
typedef struct Node{
  int vertex;
  struct Node* next;
}Node;


typedef struct {
  int numVertices;
  struct Node** adjLists;
}Graph;

// Create a node
Node* createNode(int v) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create a graph
Graph* createAGraph(int vertices) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  //assign memory to adjLists
  //adjLists:list of list of nodes 
  int i;
  for (i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

// Add edge
void addEdge(Graph* graph, int s, int d) {
  // Add edge from s to d
  Node* newNode = createNode(d);
  newNode->next = graph->adjLists[s];
  graph->adjLists[s] = newNode;

  // Add edge from d to s
  newNode = createNode(s);
  newNode->next = graph->adjLists[d];
  graph->adjLists[d] = newNode;
}

// Print the graph as lists
void printLists(Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    Node* temp = graph->adjLists[v];
    printf("\n Vertex %d\n: ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}


/* function to initialize the matrix to zero */  
void init(int arr[][V]) {  
  int i, j;  
  for (i = 0; i < V; i++)  
    for (j = 0; j < V; j++)  
      arr[i][j] = 0;  
}  


/* function to add edges to the graph */  
void insertEdge(int arr[][V], int i, int j) {  
  arr[i][j] = 1;  
  arr[j][i] = 1;  
}  


/* function to print the matrix elements */  
void printAdjMatrix(int arr[][V]) {  
  int i, j;  
  for (i = 0; i < V; i++) {  
    printf("%d: ", i);  
    for (j = 0; j < V; j++) {  
      printf("%d ", arr[i][j]);  
    }  
    printf("\n");  
  }  
}  

int main() {
  Graph* graph = createAGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 0, 3);
  addEdge(graph, 1, 2);

  printLists(graph);

   int adjMatrix[V][V];  
  
  init(adjMatrix);  
  insertEdge(adjMatrix, 0, 1);  
  insertEdge(adjMatrix, 0, 2);  
  insertEdge(adjMatrix, 1, 2);  
  insertEdge(adjMatrix, 2, 0);  
  insertEdge(adjMatrix, 2, 3);  
  
  printAdjMatrix(adjMatrix);  
  

  return 0;
}




 


  

  

  

 
