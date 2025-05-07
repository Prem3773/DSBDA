#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> graph;  // Adjacency matrix

public:
    Graph(int vertices) {
        V = vertices;
        graph = vector<vector<int>>(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight) {
        graph[src][dest] = weight;
        graph[dest][src] = weight;  // Undirected graph
    }

    void primMST() {
        vector<int> parent(V, -1);    // Array to store MST
        vector<int> key(V, INT_MAX);  // Key values used to pick minimum weight edge
        vector<bool> inMST(V, false); // Track vertices included in MST

        // Start with first vertex
        key[0] = 0;

        // Construct MST with V vertices
        for(int count = 0; count < V - 1; count++) {
            // Pick vertex with minimum key value
            int minKey = INT_MAX, u = -1;
            for(int v = 0; v < V; v++) {
                if(!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            inMST[u] = true;

            // Update key values of adjacent vertices
            for(int v = 0; v < V; v++) {
                if(graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        // Print MST
        printMST(parent);
    }

private:
    void printMST(vector<int>& parent) {
        int totalWeight = 0;
        cout << "Edge \tWeight\n";
        for(int i = 1; i < V; i++) {
            cout << parent[i] + 1 << " - " << i + 1 << "\t" 
                 << graph[i][parent[i]] << endl;
            totalWeight += graph[i][parent[i]];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    Graph g(V);
    
    cout << "\nEnter the number of edges: ";
    int E;
    cin >> E;
    
    cout << "\nEnter edges in format: source destination weight" << endl;
    cout << "(Vertices are numbered from 1 to " << V << ")" << endl;
    
    for(int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Edge " << i+1 << ": ";
        cin >> src >> dest >> weight;
        
        // Convert 1-based input to 0-based indexing
        if(src >= 1 && src <= V && dest >= 1 && dest <= V) {
            g.addEdge(src-1, dest-1, weight);
        } else {
            cout << "Invalid vertex numbers! Please enter vertices from 1 to " << V << endl;
            i--; // Retry this edge input
        }
    }
    
    cout << "\nFinding Minimum Spanning Tree:\n";
    g.primMST();

    return 0;
}