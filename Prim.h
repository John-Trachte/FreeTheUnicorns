#ifndef PRIM_H
#define PRIM_H

#include "Edge.h"
#include <queue>
#include <vector>
#include <functional>
#include <unordered_set>

void printQueue(std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue);

std::vector<edge> prim(std::vector<std::vector<int>> graph, int vertexCount);

void printMST(const std::vector<edge> minSpanTree);

std::vector<edge> toEdges(std::vector<int> vertex, int vertexNum);

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
 * @return minimum spanning tree as a vector of edges
 */
std::vector<edge> prim(std::vector<std::vector<int>> graph, int vertexCount)
{
    std::vector<edge> minSpanTree;
    // std::unordered_set<int> visitedNodes;
    bool visitedNodes[vertexCount] = {false};

    std::priority_queue<edge, std::vector<edge>, edgeComparison> minQueue;

    std::vector<edge> vertexZero = toEdges(graph[0], 0);
    for (edge edge : vertexZero)
        minQueue.push(edge);

    edge temp;
    while (!(minQueue.empty()))
    {
        temp = minQueue.top();

        minQueue.pop();

        if (false == visitedNodes[temp.parentVertex])
        {
            visitedNodes[temp.parentVertex] = true;
            minSpanTree.push_back(temp);

            std::vector<edge> nextVertex = toEdges(graph[temp.nextVertex], temp.nextVertex);
            for (edge edge : nextVertex)
                minQueue.push(edge);

            printEdge(&temp);
            std::cout << "\n\n";
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
    int i;
    std::cout << "[";
    for (i = 0; i < minSpanTree.size() - 2; i++)
    {
        std::cout << minSpanTree[i].parentVertex + 1 << "-" << minSpanTree[++i].parentVertex + 1 << ", ";
    }
    std::cout << minSpanTree[i].parentVertex + 1 << "-" << minSpanTree[++i].parentVertex + 1 << "]";
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