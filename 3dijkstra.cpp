#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;  // {destination, weight}

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});  // For undirected graph
    }

    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        // Priority queue of {distance, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print results
        cout << "\nShortest distances from vertex " << start + 1 << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i + 1 << ": ";
            if (dist[i] == INT_MAX)
                cout << "Not reachable";
            else
                cout << dist[i];
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    
    Graph g(V);
    
    cout << "Enter number of edges: ";
    cin >> E;
    
    cout << "\nEnter edges (source destination weight):\n";
    cout << "(Vertices are numbered from 1 to " << V << ")\n";
    
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cout << "Edge " << i+1 << ": ";
        cin >> src >> dest >> weight;
        
        if (src >= 1 && src <= V && dest >= 1 && dest <= V) {
            g.addEdge(src-1, dest-1, weight);
        } else {
            cout << "Invalid vertices! Please enter vertices from 1 to " << V << "\n";
            i--;
        }
    }

    int start;
    cout << "\nEnter starting vertex (1 to " << V << "): ";
    cin >> start;
    
    if (start >= 1 && start <= V) {
        g.dijkstra(start-1);
    } else {
        cout << "Invalid starting vertex!\n";
    }

    return 0;
}