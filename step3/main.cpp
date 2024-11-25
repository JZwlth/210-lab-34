#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    map<int, list<pair<int, int>>> adjList;

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    void sortAdjacency() {
        for (auto& node : adjList) {
            node.second.sort();
        }
    }

    void printGraph() {
        cout << "City Transportation Network:\n";
        for (auto& node : adjList) {
            cout << "Station " << node.first << " connects to:\n";
            for (auto& neighbor : node.second) {
                cout << "  → Station " << neighbor.first << " (Travel Time: " << neighbor.second << " mins)\n";
            }
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
        cout << "\nTour Planning (DFS) starting from Station " << start << ":\n";
        set<int> visited;
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        cout << "\nReachable Stations (BFS) from Station " << start << ":\n";
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
    Graph g(9);

    // Stations: 0 - Central Station, 1 - North Station, 2 - East Station, etc.
    g.addEdge(0, 1, 8);   // C to N
    g.addEdge(0, 2, 21);  // C to E
    g.addEdge(1, 2, 6);   // N to E
    g.addEdge(1, 3, 5);   // N to M
    g.addEdge(1, 4, 4);   // N to P
    g.addEdge(2, 7, 11);  // E to A
    g.addEdge(2, 8, 8);   // E to S
    g.addEdge(3, 4, 9);   // M to P
    g.addEdge(5, 6, 10);  // S to W
    g.addEdge(5, 7, 15);  // S to A
    g.addEdge(5, 8, 5);   // S to S
    g.addEdge(6, 7, 3);   // W to A
    g.addEdge(6, 8, 7);   // W to S
    g.addEdge(7, 2, 11);  // A to E
    g.addEdge(7, 5, 15);  // A to S
    g.addEdge(7, 6, 3);   // A to W
    g.addEdge(8, 2, 8);   // S to E
    g.addEdge(8, 5, 5);   // S to S
    g.addEdge(8, 6, 7);   // S to W


    g.sortAdjacency();
    g.printGraph();

    // Find DFS and BFS
    g.DFS(0);

    g.BFS(0);

    return 0;
}
