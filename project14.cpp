/*
    Author: Lydia Frame
    Date: July 25, 2025
    File: project14.cpp
    Description:
        Main program for Project 14.
        Builds a graph and gives the user the option to run
        either the Unweighted Shortest Path or Depth First Search.
*/

#include <iostream>
#include <vector>
#include "Graph.h"

int main() {
    int n;
    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n));

    std::cout << "Enter connectivity matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> adjMatrix[i][j];

    Graph graph(n, adjMatrix);

    int choice;
    std::cout << "\nChoose an option:\n";
    std::cout << "1. Unweighted Shortest Path\n";
    std::cout << "2. Depth First Search (DFS)\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        int start, end;
        std::cout << "Enter starting node: ";
        std::cin >> start;
        std::cout << "Enter ending node: ";
        std::cin >> end;
        graph.unweighted(start);
        graph.printPath(start, end);
    } else if (choice == 2) {
        int start;
        std::cout << "Enter starting node for DFS: ";
        std::cin >> start;
        graph.dfs(start);
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}