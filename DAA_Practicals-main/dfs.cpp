#include <iostream>
#include <vector>
#include <stack>
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
        adj[v].push_back(u); // For undirected graph
    }

    void DFSUtil(int start, vector<bool>& visited) {
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int current = stk.top();
            stk.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;

                // for (int neighbor : adj[current]) {
                for (std::vector<int>::iterator it = adj[current].begin(); it!= adj[current].end(); ++it) {
                    int neighbor = *it;
                    if (!visited[neighbor]) {
                        stk.push(neighbor);
                    }
                }
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    cout << "DFS Traversal: ";
    graph.DFS(0);
    cout << endl;

    return 0;
}
