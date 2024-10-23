// Write a program to implement traversal of a graph through DFS

#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{ // Corrected the typedef declaration
    Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph; // Note the semicolon here

// Function to create a new node
Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Uncomment the next two lines for an undirected graph
    // newNode = createNode(src);
    // newNode->next = graph->adjLists[dest];
    // graph->adjLists[dest] = newNode;
}

// DFS algorithm
void dfs(Graph *graph, int vertex)
{
    graph->visited[vertex] = 1; // Mark the vertex as visited
    printf("%d ", vertex);      // Print the vertex

    Node *adjList = graph->adjLists[vertex];
    Node *temp = adjList;

    // Traverse all adjacent vertices
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            dfs(graph, connectedVertex); // Recursively visit unvisited vertices
        }
        temp = temp->next;
    }
}

// Main function
int main()
{
    int vertices, edges;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Create a graph
    Graph *graph = createGraph(vertices);

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Input edges
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    // Start DFS traversal from vertex 0
    printf("Depth First Search starting from vertex 0:\n");
    dfs(graph, 0);

    return 0;
}
// Enter the number of vertices: 5
// Enter the number of edges: 6
// Enter edges (src dest):
// Edge 1: 0 1
// Edge 2: 0 2
// Edge 3: 1 3
// Edge 4: 1 4
// Edge 5: 2 4
// Edge 6: 3 4
// Depth First Search starting from vertex 0:
// 0 2 4 1 3