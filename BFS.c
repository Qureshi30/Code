
//  Write a program to implement traversal of a graph through BFS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

typedef struct Graph
{
    Node *adjLists[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;

Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

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

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

Queue *createQueue()
{
    Queue *queue = malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->rear == -1;
}

void enqueue(Queue *queue, int value)
{
    if (queue->rear == MAX_VERTICES - 1)
        return;
    if (queue->front == -1)
        queue->front = 0;
    queue->items[++queue->rear] = value;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->items[queue->front];
    if (queue->front >= queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return item;
}

void bfs(Graph *graph, int startVertex)
{
    Queue *queue = createQueue();
    graph->visited[startVertex] = 1;
    printf("%d ", startVertex);
    enqueue(queue, startVertex);

    while (!isEmpty(queue))
    {
        int currentVertex = dequeue(queue);
        Node *adjList = graph->adjLists[currentVertex];
        Node *temp = adjList;

        while (temp != NULL)
        {
            int connectedVertex = temp->vertex;
            if (graph->visited[connectedVertex] == 0)
            {
                graph->visited[connectedVertex] = 1;
                printf("%d ", connectedVertex);
                enqueue(queue, connectedVertex);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    Graph *graph = createGraph(vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (in the format 'src dest'):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printf("Breadth First Search starting from vertex 0:\n");
    bfs(graph, 0);

    // Free allocated memory
    for (int i = 0; i < vertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);

    return 0;
}
// Enter the number of vertices: 5
// Enter the number of edges: 6
// Enter the edges (in the format 'src dest'):
// Edge 1: 0 1
// Edge 2: 0 2
// Edge 3: 1 3
// Edge 4: 1 4
// Edge 5: 2 4
// Edge 6: 3 4
// Breadth First Search starting from vertex 0:
// 0 1 2 3 4

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// // Define the structure for a node in the adjacency list
// struct Node
// {
//     int vertex;
//     struct Node *next;
// };

// // Define the structure for the graph
// struct Graph
// {
//     int numVertices;
//     struct Node **adjLists; // Array of adjacency lists
// };

// // Function to create a new adjacency list node
// struct Node *createNode(int v)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// // Function to create a graph
// struct Graph *createGraph(int vertices)
// {
//     struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;

//     // Create an array of adjacency lists
//     graph->adjLists = (struct Node **)malloc(vertices * sizeof(struct Node *));

//     // Initialize each adjacency list as empty
//     for (int i = 0; i < vertices; i++)
//     {
//         graph->adjLists[i] = NULL;
//     }
//     return graph;
// }

// // Function to add an edge to the graph
// void addEdge(struct Graph *graph, int src, int dest)
// {
//     // Add an edge from src to dest
//     struct Node *newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;

//     // Since the graph is undirected, add an edge from dest to src
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }

// // Function to perform BFS traversal of the graph
// void BFS(struct Graph *graph, int startVertex)
// {
//     bool *visited = (bool *)malloc(graph->numVertices * sizeof(bool));
//     for (int i = 0; i < graph->numVertices; i++)
//     {
//         visited[i] = false; // Mark all vertices as unvisited
//     }

//     // Create a queue for BFS
//     int queue[graph->numVertices];
//     int front = 0;
//     int rear = 0;

//     // Mark the starting vertex as visited and enqueue it
//     visited[startVertex] = true;
//     queue[rear++] = startVertex;

//     printf("BFS Traversal starting from vertex %d: ", startVertex);

//     while (front < rear)
//     {
//         // Dequeue a vertex from queue and print it
//         int currentVertex = queue[front++];
//         printf("%d ", currentVertex);

//         // Get all adjacent vertices of the dequeued vertex
//         struct Node *temp = graph->adjLists[currentVertex];
//         while (temp)
//         {
//             int adjVertex = temp->vertex;

//             // If the adjacent vertex has not been visited, mark it visited and enqueue it
//             if (!visited[adjVertex])
//             {
//                 visited[adjVertex] = true;
//                 queue[rear++] = adjVertex;
//             }
//             temp = temp->next;
//         }
//     }

//     printf("\n");
//     free(visited);
// }

// // Function to display the graph
// void displayGraph(struct Graph *graph)
// {
//     for (int v = 0; v < graph->numVertices; v++)
//     {
//         struct Node *temp = graph->adjLists[v];
//         printf("Vertex %d: ", v);
//         while (temp)
//         {
//             printf("-> %d ", temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// // Main function
// int main()
// {
//     int vertices = 5; // Number of vertices
//     struct Graph *graph = createGraph(vertices);

//     // Adding edges to the graph
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 3);
//     addEdge(graph, 1, 4);
//     addEdge(graph, 2, 4);

//     // Display the graph
//     printf("Graph adjacency list:\n");
//     displayGraph(graph);

//     // Perform BFS traversal
//     BFS(graph, 0); // Starting BFS from vertex 0

//     // Free the graph memory
//     for (int i = 0; i < vertices; i++)
//     {
//         struct Node *temp = graph->adjLists[i];
//         while (temp)
//         {
//             struct Node *next = temp->next;
//             free(temp);
//             temp = next;
//         }
//     }
//     free(graph->adjLists);
//     free(graph);

//     return 0;
// }
