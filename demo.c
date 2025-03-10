#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100000

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node** adjacencyList;
};

// Function to initialize a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of nodes
struct Graph* createGraph(int numNodes) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numNodes = numNodes;
    graph->adjacencyList = (struct Node**)malloc(numNodes * sizeof(struct Node*));

    for (int i = 0; i < numNodes; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjacencyList[u];
    graph->adjacencyList[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adjacencyList[v];
    graph->adjacencyList[v] = newNode;
}

// Depth-First Search (DFS) function
void DFS(struct Graph* graph, int node, bool* visited) {
    visited[node] = true;

    struct Node* temp = graph->adjacencyList[node];
    while (temp != NULL) {
        int neighbor = temp->data;
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
        temp = temp->next;
    }
}

// Function to count the number of connected components
int countConnectedComponents(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->numNodes * sizeof(bool));
    for (int i = 0; i < graph->numNodes; i++) {
        visited[i] = false;
    }

    int components = 0;
    for (int i = 0; i < graph->numNodes; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
            components++;
        }
    }

    free(visited);
    return components;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    struct Graph* graph = createGraph(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u - 1, v - 1); // Convert to 0-based index
    }

    int components = countConnectedComponents(graph);
    printf("%d\n", components);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(graph->adjacencyList);
    free(graph);

    return 0;
}
