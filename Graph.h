/*
    Author: Lydia Frame
    Date: July 25, 2025
    Description:
        Graph class for Project 14.
        Adds a DFS method using the GraphNode 'visited' flag.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <vector>
#include <queue>
#include <iostream>

class Graph {
private:
    std::vector<GraphNode*> nodes;

    void dfsVisit(GraphNode* node) {
        node->setVisited(true);
        std::cout << "Visited: " << node->getId() << std::endl;

        for (GraphNode* neighbor : node->getAdj()) {
            if (!neighbor->isVisited()) {
                dfsVisit(neighbor);
            }
        }
    }

public:
    Graph(int n, const std::vector<std::vector<int>>& adjMatrix) {
        for (int i = 0; i < n; ++i)
            nodes.push_back(new GraphNode(i));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adjMatrix[i][j])
                    nodes[i]->addNeighbor(nodes[j]);
    }

    ~Graph() {
        for (auto node : nodes)
            delete node;
    }

    void unweighted(int startId) {
        for (auto node : nodes) {
            node->setDist(-1);
            node->setPath(nullptr);
        }

        GraphNode* start = nodes[startId];
        start->setDist(0);

        std::queue<GraphNode*> q;
        q.push(start);

        while (!q.empty()) {
            GraphNode* current = q.front();
            q.pop();

            for (auto neighbor : current->getAdj()) {
                if (neighbor->getDist() == -1) {
                    neighbor->setDist(current->getDist() + 1);
                    neighbor->setPath(current);
                    q.push(neighbor);
                }
            }
        }
    }

    void printPath(int startId, int endId) {
        GraphNode* end = nodes[endId];
        if (end->getDist() == -1) {
            std::cout << "No path from " << startId << " to " << endId << ".\n";
            return;
        }

        std::vector<int> path;
        for (GraphNode* node = end; node != nullptr; node = node->getPath())
            path.push_back(node->getId());

        std::cout << "Distance: " << end->getDist() << "\nPath: ";
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            std::cout << *it << (it + 1 != path.rend() ? " -> " : "\n");
    }

    void resetVisited() {
        for (auto node : nodes)
            node->setVisited(false);
    }

    void dfs(int startId) {
        resetVisited();
        std::cout << "Starting DFS from node " << startId << ":\n";
        dfsVisit(nodes[startId]);
    }
};

#endif