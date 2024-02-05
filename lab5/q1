#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int numVertices;
    Node* adjacencyList[MAX_VERTICES];
    int* indegree;
} Graph;

// Function to create a new graph node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->indegree = (int*)calloc(numVertices, sizeof(int));
    for (int i = 0; i < numVertices; ++i)
        graph->adjacencyList[i] = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    graph->indegree[dest]++;
}

// Function to perform Depth-First Search and Topological Sort
void dfsTopologicalSort(Graph* graph, int v, int visited[], int stack[]) {
    visited[v] = 1;
    Node* temp = graph->adjacencyList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex])
            dfsTopologicalSort(graph, adjVertex, visited, stack);
        temp = temp->next;
    }
    stack[--stack[0]] = v;
}

// Function to perform Topological Sort using Depth-First technique
void topologicalSortDFS(Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; ++i) {
        if (!visited[i])
            dfsTopologicalSort(graph, i, visited, stack);
    }

    printf("Topological Sort using Depth-First technique: ");
    for (int i = 1; i <= graph->numVertices; ++i)
        printf("%d ", stack[i]);
    printf("\n");
}

// Function to perform Topological Sort using Source Removal technique
void topologicalSortSourceRemoval(Graph* graph) {
    int stack[MAX_VERTICES] = {0};
    int top = -1;

    int* indegree = graph->indegree;

    for (int i = 0; i < graph->numVertices; ++i) {
        if (indegree[i] == 0)
            stack[++top] = i;
    }

    printf("Topological Sort using Source Removal technique: ");
    while (top != -1) {
        int v = stack[top--];
        printf("%d ", v);

        Node* temp = graph->adjacencyList[v];
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            indegree[adjVertex]--;
            if (indegree[adjVertex] == 0)
                stack[++top] = adjVertex;
            temp = temp->next;
        }
    }
    printf("\n");
}

// Driver function
int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSortDFS(graph);
    topologicalSortSourceRemoval(graph);

    return 0;
}
