#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int> > adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void BFS(int start) {
        queue<int> q;
        unordered_set<int> visited;
        q.push(start);
        visited.insert(start);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            // for (int neighbor : adj[current]) {
            for (std::vector<int>::iterator it = adj[current].begin(); it!= adj[current].end(); ++it) {
                int neighbor = *it;
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    cout << "BFS Traversal: ";
    graph.BFS(0);
    cout << endl;
    return 0;
}
