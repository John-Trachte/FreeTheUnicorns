#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <vector>

/**
 * Read graph from the provided filePath with vertexCount vertices
 * @param filePath path of the file to be read from
 * @param vertexCount total number of vertices in the graph
 */
std::vector<std::vector<int>> readGraph(char *filePath, int vertexCount)
{
    std::vector<std::vector<int>> graph;
    std::vector<int> vertex;

    int next;
    char comma;

    std::ifstream file;
    file.open(filePath);

    if (file.is_open())
    {
        while (file.good())
        {
            for (int i = 0; i < vertexCount; i++)
            {
                file >> next;
                comma = file.peek();

                if (',' == comma)
                    file >> comma;

                vertex.push_back(next);
            }
            graph.push_back(vertex);
            vertex.clear();
        }
    }
    else
    {
        std::cout << "File not found, exiting...";
        file.close();

        exit(1);
    }

    file.close();

    return graph;
}


/**
 * Print a text representation of the input graph; primarily used for debugging
 * @param graph vector<vector<int>> representing the vertices and edges of a graph
*/
void printGraph(std::vector<std::vector<int>> graph)
{
    for (std::vector<int> vertex : graph)
    {
        for (int i = 0; i < vertex.size() - 1; i++)
        {
            std::cout << vertex[i] << ", ";
        }
        std::cout << vertex[vertex.size() - 1] << "\n";
    }
}

#endif