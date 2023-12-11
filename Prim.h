#ifndef PRIM_H
#define PRIM_H

#include "Edge.h"
#include <queue>
#include <vector>
#include <functional>

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

std::vector<std::vector<int>> prim(std::vector<std::vector<int>> graph, int vertexCount)
{
    std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue;

    edge first = {
        10, 0, 3};

    edge second = {
        11, 0, 3};

    edge third = {
        12, 0, 3};

    minQueue.push(first);
    minQueue.push(second);
    minQueue.push(third);

    printQueue(minQueue);

    exit(1);
}

std::vector<edge> toEdges(std::vector<int> vertex)
{
    std::vector<edge> edges;
}

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