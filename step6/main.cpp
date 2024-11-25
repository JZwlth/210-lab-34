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
        cout << "\nCity Transportation Network:\n";
        for (auto& node : adjList) {
            cout << "Station " << node.first << " connects to:\n";
            for (auto& neighbor : node.second) {
                cout << "  → Station " << neighbor.first << " (Travel Time: " << neighbor.second << " mins)\n";
            }
        }
    }

    void DFSUtil(int v, set<int>& visited) {
        visited.insert(v);
        cout << "Visiting Station " << v << endl;
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
            cout << "At Station " << v << endl;

            for (auto& neighbor : adjList[v]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    q.push(neighbor.first);
                }
            }
        }
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

        cout << "\nShortest travel times from Station " << start << ":\n";
        for (auto& dist : distances) {
            cout << "To Station " << dist.first << " : " << dist.second << " mins" << endl;
        }
    }

    void minimumSpanningTree() {
        map<int, int> key;
        map<int, int> parent;
        set<int> inMST;

        for (auto& node : adjList) {
            key[node.first] = INT_MAX;
        }

        int start = adjList.begin()->first;
        key[start] = 0;
        parent[start] = -1;

        set<pair<int, int>> pq;
        pq.insert(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.begin()->second;
            pq.erase(pq.begin());
            inMST.insert(u);

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (inMST.find(v) == inMST.end() && key[v] > weight) {
                    if (key[v] != INT_MAX) {
                        pq.erase(pq.find(make_pair(key[v], v)));
                    }
                    key[v] = weight;
                    pq.insert(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        cout << "\nMinimum Spanning Tree of the Network:\n";
        for (auto& node : adjList) {
            int v = node.first;
            if (parent.find(v) != parent.end() && parent[v] != -1) {
                cout << "Edge from Station " << parent[v] << " to Station " << v << " with travel time: " << key[v] << " mins" << endl;
            }
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

    int choice;
    do {
        cout << "\nCity Transportation Network Menu:\n";
        cout << "[1] Display network\n";
        cout << "[2] Plan a tour (DFS)\n";
        cout << "[3] Find reachable stations (BFS)\n";
        cout << "[4] Calculate shortest travel times\n";
        cout << "[5] Find Minimum Spanning Tree\n";
        cout << "[0] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g.printGraph();
                break;
            case 2:
                g.DFS(0);
                break;
            case 3:
                g.BFS(0);
                break;
            case 4:
                g.shortestPath(0);
                break;
            case 5:
                g.minimumSpanningTree();
                break;
            case 0:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please select again.\n";
        }
    } while (choice != 0);

    return 0;
}
