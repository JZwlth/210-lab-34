#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    map<int, list<pair<int, int>>> adjList;

public:
    Graph(int V) { this->V = V; }

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

    void shortestPath(int start) {
        map<int, int> distances;
        for (auto& node : adjList) {
            distances[node.first] = INT_MAX;
        }
        distances[start] = 0;

        set<pair<int, int>> pq;
        pq.insert(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.begin()->second;
            pq.erase(pq.begin());

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distances[u] + weight < distances[v]) {
                    if (distances[v] != INT_MAX) {
                        pq.erase(pq.find(make_pair(distances[v], v)));
                    }
                    distances[v] = distances[u] + weight;
                    pq.insert(make_pair(distances[v], v));
                }
            }
        }

        cout << "Shortest path from node " << start << ":\n";
        for (auto& dist : distances) {
            cout << start << " -> " << dist.first << " : " << dist.second << endl;
        }
    }
};

int main() {
    Graph g(9);

    g.addEdge(0, 1, 8);
    g.addEdge(0, 2, 21);
    g.addEdge(1, 2, 6);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 4);
    g.addEdge(2, 7, 11);
    g.addEdge(2, 8, 8);
    g.addEdge(3, 4, 9);
    g.addEdge(5, 6, 10);
    g.addEdge(5, 7, 15);
    g.addEdge(5, 8, 5);
    g.addEdge(6, 7, 3);
    g.addEdge(6, 8, 7);
    g.addEdge(7, 2, 11);
    g.addEdge(7, 5, 15);
    g.addEdge(7, 6, 3);
    g.addEdge(8, 2, 8);
    g.addEdge(8, 5, 5);
    g.addEdge(8, 6, 7);

    g.sortAdjacency();
    g.printGraph();
    g.DFS(0);
    g.BFS(0);
    g.shortestPath(0);

    return 0;
}
