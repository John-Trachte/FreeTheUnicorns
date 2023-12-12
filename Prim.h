#ifndef PRIM_H
#define PRIM_H

#include "Edge.h"
#include <queue>
#include <vector>
#include <functional>

void printQueue(std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue);

std::vector<edge> prim(std::vector<std::vector<int>> graph, int vertexCount);

void printMST(const std::vector<edge> minSpanTree);

std::vector<edge> toEdges(std::vector<int> vertex, int vertexNum);

void printVisitedVertices(bool vistedVertices[], int length);

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

void printVisitedVertices(bool vistedVertices[], int length)
{
    for (int i = 0; i < length; i++)
        std::cout << i << ": " << vistedVertices[i] << ", ";
    std::cout << "\n";
}

/**
 * Implement Prim's algorithm on the parameter graph with vertexCount vertices
 * @param graph graph whose minimum spanning tree is found
 * @param vertexCount number of vertices in @param graph
 * @return minimum spanning tree as a vector of edges
 */
std::vector<edge> prim(std::vector<std::vector<int>> graph, int vertexCount)
{
    std::vector<edge> minSpanTree;
    bool visitedVertices[vertexCount] = {false};
    visitedVertices[0] = true;

    std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue;

    std::vector<edge> vertexZero = toEdges(graph[0], 0);
    for (edge edge : vertexZero)
        minQueue.push(edge);

    edge temp;
    while (!(minQueue.empty()))
    {
        // printVisitedVertices(visitedVertices, sizeof(visitedVertices) / sizeof(bool));
        // printQueue(minQueue);
        temp = minQueue.top();

        minQueue.pop();

        if (false == visitedVertices[temp.nextVertex])
        {
            visitedVertices[temp.nextVertex] = true;
            minSpanTree.push_back(temp);

            std::vector<edge> nextVertex = toEdges(graph[temp.nextVertex], temp.nextVertex);
            for (edge edge : nextVertex)
                minQueue.push(edge);

            // printEdge(&temp);
            // std::cout << "\n\n";
        }
    }

    return minSpanTree;
}

/**
 * Prints a passed in minimum spanning tree
 * @param minSpanTree minimum spanning tree to be printed
 */
void printMST(const std::vector<edge> minSpanTree)
{
    std::cout << "MST:\n[";
    int i;
    for (i = 0; i < minSpanTree.size() - 1; i++)
        std::cout << minSpanTree[i].parentVertex + 1 << "-" << minSpanTree[i].nextVertex + 1 << ", ";
    std::cout << minSpanTree[i].parentVertex + 1 << "-" << minSpanTree[i].nextVertex + 1 << "]";
}

/**
 * Convert a vertex to a set of edge structs
 * @param vertex vector of integers to be converted into edge structs
 * @param vertexNum parentVertex of each edge struct
 * @return converted vertex
 */
std::vector<edge> toEdges(std::vector<int> vertex, int vertexNum)
{
    std::vector<edge> edges;

    for (int i = 0; i < vertex.size(); i++)
    {
        edge temp = {vertex[i], vertexNum, i};
        if (temp.weight > 0)
            edges.push_back(temp);
    }

    return edges;
}

#endif