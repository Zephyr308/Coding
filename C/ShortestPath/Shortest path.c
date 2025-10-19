#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

// -----------------------------------------------------------------------------
// Function: getIndex
// Purpose : Returns the index of a node name from the nodes array
// Inputs  : name  - the node name to search for
//           nodes - array of node names
//           N     - number of nodes
// Returns : index of the node if found, -1 otherwise
// -----------------------------------------------------------------------------
int getIndex(char* name, char *nodes[], int N) {
    for (int i = 0; i < N; i++) {
        if (strcmp(name, nodes[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// -----------------------------------------------------------------------------
// Function: ShortestPath
// Purpose : Computes and prints the shortest path from the first to last node
//           using Dijkstra’s algorithm in a directed unweighted graph
// Inputs  : strArr     - input array containing node count, node names, and edges
//           arrLength - total number of elements in strArr
// -----------------------------------------------------------------------------
void ShortestPath(char *strArr[], int arrLength) {
    int N = atoi(strArr[0]);  // Number of nodes
    char *nodes[N];

    // Extract node names (from index 1 to N)
    for (int i = 0; i < N; i++) {
        nodes[i] = strArr[i + 1];
    }

    // Initialize adjacency matrix with INT_MAX (representing no direct edge)
    int graph[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = INT_MAX;

    // Parse edges from strArr[N + 1] to strArr[arrLength - 1]
    for (int i = N + 1; i < arrLength; i++) {
        char *edge = strdup(strArr[i]); // Copy string to safely tokenize
        char *src = strtok(edge, "-");
        char *dest = strtok(NULL, "-");

        int u = getIndex(src, nodes, N);
        int v = getIndex(dest, nodes, N);

        if (u != -1 && v != -1) {
            graph[u][v] = 1; // Set edge weight to 1 (unweighted graph)
        }

        free(edge); // Free duplicated string
    }

    // Initialize Dijkstra variables
    int dist[N], visited[N], prev[N];
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;   // Distance from source to i
        visited[i] = 0;      // Visited flag
        prev[i] = -1;        // Previous node in path
    }

    dist[0] = 0; // Source node distance is 0

    // Dijkstra's algorithm to compute shortest distances
    for (int count = 0; count < N - 1; count++) {
        int minDist = INT_MAX, minIndex = -1;

        // Select the unvisited node with the smallest distance
        for (int v = 0; v < N; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        if (minIndex == -1)
            break;

        visited[minIndex] = 1;

        // Update distances of adjacent unvisited nodes
        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[minIndex][v] != INT_MAX &&
                dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
                prev[v] = minIndex;
            }
        }
    }

    // Reconstruct shortest path from sink to source
    int path[N], len = 0;
    int at = N - 1; // Sink is the last node

    while (at != -1) {
        path[len++] = at;
        at = prev[at];
    }

    // If sink is unreachable, print error
    if (dist[N - 1] == INT_MAX) {
        printf("No path found from %s to %s\n", nodes[0], nodes[N - 1]);
        return;
    }

    // Print the path from source to sink
    for (int i = len - 1; i >= 0; i--) {
        printf("%s", nodes[path[i]]);
        if (i > 0) printf("-");
    }
    printf("\n");
}

// -----------------------------------------------------------------------------
// Main Function
// Purpose: Run multiple test cases for the shortest path function
// -----------------------------------------------------------------------------
int main(void) {
    // Test Case 1: Simple linear path
    char *input1[] = {"4", "A", "B", "C", "D", "A-B", "B-C", "C-D"};
    
    // Test Case 2: Multiple path options (A-E is shorter than A-B-C-D-E)
    char *input2[] = {"5", "A", "B", "C", "D", "E", "A-B", "B-C", "C-D", "D-E", "A-E"};
    
    // Test Case 3: Graph with a cycle
    char *input3[] = {"3", "A", "B", "C", "A-B", "B-C", "C-A"};
    
    // Test Case 4: Longer graph with shortcut (A-F)
    char *input4[] = {"6", "A", "B", "C", "D", "E", "F", "A-B", "B-C", "C-D", "D-E", "E-F", "A-F"};

    // Run all test cases
    ShortestPath(input1, sizeof(input1) / sizeof(input1[0]));
    ShortestPath(input2, sizeof(input2) / sizeof(input2[0]));
    ShortestPath(input3, sizeof(input3) / sizeof(input3[0]));
    ShortestPath(input4, sizeof(input4) / sizeof(input4[0]));

    return 0;
}
