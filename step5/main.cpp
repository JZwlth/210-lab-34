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
    g.minimumSpanningTree();

    return 0;
}