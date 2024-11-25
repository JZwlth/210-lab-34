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
        cout << "DFS starting from vertex"

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



    