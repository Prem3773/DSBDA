#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Graph {
    public:
    map<int, list<int>> adjList;
    map<int, bool> visited;
    queue<int> q;
    
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
        cout << "Edge added between " << src << " and " << dest << endl;
    }

    void DFS(int node) {
        visited[node] = true;
        cout << node << " ";
        for(int i : adjList[node]) {
            if(!visited[i]) DFS(i);
        }
    }

    void BFS() {
        if(q.empty()) return;
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int i : adjList[node]) {
            if(!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
        BFS();
    }

    void clearVisited() {
        visited.clear();
    }
};

int main() {
    Graph g;
    int nodes, edges;
    
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    cout << "\nEnter " << edges << " edges (source destination):\n";
    for(int i = 0; i < edges; i++) {
        int src, dest;
        cout << "Edge " << i+1 << ": ";
        cin >> src >> dest;
        
        // Validate input
        if(src >= nodes || dest >= nodes || src < 0 || dest < 0) {
            cout << "Invalid node numbers! Nodes should be between 0 to " << nodes-1 << endl;
            i--; // Retry this edge input
            continue;
        }
        g.addEdge(src, dest);
    }
    
    while(true) {
        cout << "\n=== Graph Traversal Menu ===";
        cout << "\n1. Perform DFS";
        cout << "\n2. Perform BFS";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "DFS Traversal: ";
                g.clearVisited();
                g.DFS(0);
                cout << endl;
                break;
                
            case 2:
                cout << "BFS Traversal: ";
                g.clearVisited();
                g.q.push(0);
                g.visited[0] = true;
                g.BFS();
                cout << endl;
                break;
                
            case 3:
                cout << "Exiting program...\n";
                return 0;
                
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}