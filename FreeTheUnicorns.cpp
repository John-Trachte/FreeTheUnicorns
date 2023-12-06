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
        std::cout << "File not found, exiting";
        file.close();

        exit(1);
    }

    file.close();

    return graph;
}

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