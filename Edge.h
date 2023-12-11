#ifndef EDGE_H
#define EDGE_H

#include <iostream>

struct edge
{
    int weight, parentVertex, nextVertex;
};

// https://medium.com/@taohidulii/min-priority-queue-in-c-7e64bd01359c
struct edgeComparison
{
    bool operator()(const edge &a, const edge &b)
    {
        return (a.weight < b.weight);
    }
};

void printEdge(edge *edge)
{
    std::cout << "parent: " << edge->parentVertex
              << " weight: " << edge->weight
              << " next: " << edge->nextVertex
              << "\n";
}

#endif