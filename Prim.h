#include <vector>

struct edge
{
    int weight, parentVertex;
};

std::vector<std::vector<int>> prim(std::vector<std::vector<int>> graph, int vertexCount)
{
    std::vector<std::vector<int>> validVertices;

    for (int i = 0; i < vertexCount; i++)
    {
        std::vector<int> vertex = {0};
        validVertices.push_back(vertex);
    }
}

edge minDistance(std::vector<std::vector<int>> validVertices)
{
    edge shortest = {0,0};
    for (int v = 0; v < validVertices.size(); v++)
    {
        for (int e = 0; e < validVertices[v].size(); e++)
        {
            if (validVertices[v][e] != 0 && validVertices[v][e] > shortest.weight)
            {
                shortest.weight = validVertices[v][e];
                shortest.parentVertex = v;
            }
        }
    }

    return shortest;
}