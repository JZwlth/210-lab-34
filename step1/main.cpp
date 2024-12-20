#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Graph {
    int V; // Number of vertices
    map<int, list<pair<int, int>>> adjList;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    // Sort 
    void sortAdjacency() {
        for (auto& node : adjList) {
            node.second.sort();
        }
    }

    // Print the adjacency list
    void printGraph() {
        cout << "Graph's adjacency list:\n";
        for (auto& node : adjList) {
            cout << node.first << " --> ";
            for (auto& neighbor : node.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    void DFSUtil(int v, set<int>& visited) {
        visited.insert(v);
        cout << v << " ";
        for (auto& neighbor : adjList[v]) {
            if (visited.find(neighbor.first) == visited.end()) {
                DFSUtil(neighbor.first, visited);
            }
        }
    }

    void DFS(int start) {
        cout << "DFS starting from vertex " << start << ":\n";
        set<int> visited;
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        cout << "BFS starting from vertex " << start << ":\n";
        set<int> visited;
        queue<int> q;
        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (auto& neighbor : adjList[v]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(7);

    // Adding edges as per the sample graph
    g.addEdge(0, 1, 12);
    g.addEdge(0, 2, 8);
    g.addEdge(0, 3, 21);
    g.addEdge(2, 3, 6);
    g.addEdge(2, 6, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 5);
    g.addEdge(4, 5, 9);
    g.addEdge(5, 6, 6);

    g.sortAdjacency();
    g.printGraph();

    g.DFS(0);
    g.BFS(0);

    return 0;
}
