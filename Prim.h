#include <vector>

struct edge
{
    int weight, parentVertex, nextVertex;
};

void printEdge(edge *edge)
{
    std::cout << "parent: " << edge->parentVertex
              << "weight: " << edge->weight
              << "next: " << edge->nextVertex
              << "\n";
}

std::vector<std::vector<int>> prim(std::vector<std::vector<int>> graph, int vertexCount)
{
    std::vector<std::vector<int>> validVertices;
    validVertices.push_back(graph[0]);

    for (int i = 0; i < vertexCount; i++)
    {
        std::vector<int> vertex = {0};
        validVertices.push_back(vertex);
    }
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