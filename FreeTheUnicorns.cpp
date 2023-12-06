#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> readGraph(char *filePath, int vertexCount);

void printGraph(std::vector<std::vector<int>> graph);

int main(int argc, char *argv[])
{
    std::vector<std::vector<int>> graph = readGraph(argv[1], atoi(argv[2]));

    printGraph(graph);

    return 0;
}

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
                file >> comma;
               
                vertex.push_back(next);

                std::cout << " n: " << next << " c: " << comma;
            }
            graph.push_back(vertex);
            vertex.clear();
        }
    }
    else
    {
        std::cout << "File not found, exiting";
        file.close();

        exit(1);
    }

    file.close();

    return graph;
}

void printGraph(std::vector<std::vector<int>> graph)
{
    std::cout << "\n";
    for (std::vector<int> vertex : graph)
    {
        for (int i = 0; i < vertex.size() - 1; i++)
        {
            std::cout << i << ", ";
        }
        std::cout << vertex[vertex.size() - 1] << "\n";
    }
}