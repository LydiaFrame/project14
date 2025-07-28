/*
    Author: Lydia Frame
    Date: July 25, 2025
    Description:
        GraphNode class for Project 14.
        Now includes 'visited' field for DFS.
*/

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>

class GraphNode {
private:
    int id;
    std::vector<GraphNode*> adj;
    int dist;
    GraphNode* path;
    bool visited; // NEW for DFS

public:
    GraphNode(int id) : id(id), dist(-1), path(nullptr), visited(false) {}

    int getId() const { return id; }
    int getDist() const { return dist; }
    GraphNode* getPath() const { return path; }
    bool isVisited() const { return visited; }

    void setDist(int d) { dist = d; }
    void setPath(GraphNode* p) { path = p; }
    void setVisited(bool v) { visited = v; }

    void addNeighbor(GraphNode* neighbor) {
        adj.push_back(neighbor);
    }

    const std::vector<GraphNode*>& getAdj() const {
        return adj;
    }
};

#endif