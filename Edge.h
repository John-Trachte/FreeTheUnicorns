#ifndef EDGE_H
#define EDGE_H

#include <iostream>

struct edge
{
    int weight, parentVertex, nextVertex;
};

/**
 * Custom comparison function for struct edge to find lesser edge
 * Based on: https://medium.com/@taohidulii/min-priority-queue-in-c-7e64bd01359c
 * @param a edge compared against
 * @param b edge compared with
*/
struct edgeComparison
{
    bool operator()(const edge &a, const edge &b)
    {
        return (a.weight > b.weight);
    }
};

void printEdge(const edge *edge);

/**
 * Print an edge's data
 * @param edge pointer to an edge struct to be printed
*/
void printEdge(const edge *edge)
{
    std::cout << "parent: " << edge->parentVertex << " "
              << "weight: " << edge->weight << " "
              << "next: " << edge->nextVertex
              << "\n";
}

#endif