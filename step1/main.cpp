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
    map<int, list<pair<int, int>>> adjList; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
    }

    // Add an undirected edge
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    // Sort adjacency list to ensure consistent traversal order
    void sortAdjacency() {
        for (auto& node : adjList) {
            node.second.sort();
        }
    }


    void printGraph() {
        cout << "Graph's adjacency list:\n";
        for (auto& nod
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
