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




