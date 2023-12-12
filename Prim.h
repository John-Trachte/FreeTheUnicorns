#ifndef PRIM_H
#define PRIM_H

#include "Edge.h"
#include <queue>
#include <vector>
#include <functional>

/**
 * Print queue parameter
 * @param minQueue queue to be printed
*/
void printQueue(std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue)
{
    std::vector<edge> storage;
    edge temp;

    while (!(minQueue.empty()))
    {
        temp = minQueue.top();
        storage.push_back(temp);
        minQueue.pop();
        printEdge(&temp);
    }

    for (edge curr : storage)
        minQueue.push(curr);
}

/**
 * Implement Prim's algorithm on the parameter graph with vertexCount vertices
 * @param graph graph whose minimum spanning tree is found
 * @param vertexCount number of vertices in @param graph
*/
std::vector<std::vector<int>> prim(std::vector<std::vector<int>> graph, int vertexCount)
{
    std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue;
    
    std::vector<edge> vertexZero = toEdges(graph[0], 0);
    for (edge edge : vertexZero)
        minQueue.push(edge);

    while (!(minQueue.empty()))
    {

    }
}

/**
 * Convert a vertex to a set of edge structs
 * @param vertex vector of integers to be converted into edge structs
 * @param vertexNum parentVertex of each edge struct
*/
std::vector<edge> toEdges(std::vector<int> vertex, int vertexNum)
{
    std::vector<edge> edges;

    for (int i = 0; i < vertex.size(); i++)
    {
        edge temp = {vertex[i], vertexNum, i};
        edges.push_back(temp);
    }

    return edges;
}

/**
 * Not currently in use
*/
edge minDistance(std::vector<std::vector<int>> validVertices)
{
    edge shortest = {0, 0, 0};
    for (int v = 0; v < validVertices.size(); v++)
    {
        for (int e = 0; e < validVertices[v].size(); e++)
        {
            if (validVertices[v][e] != 0 && validVertices[v][e] > shortest.weight)
            {
                shortest.weight = validVertices[v][e];
                shortest.parentVertex = v;
                shortest.nextVertex = e;
            }
        }
    }

    return shortest;
}

#endif