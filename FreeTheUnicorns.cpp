#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> readGraph(char* filePath);

int main(int argc, char* argv[])
{
    readGraph(argv[1]);

    return 0;
}

std::vector<int> readGraph(char* filePath)
{
    std::vector<int> graph;

    int next;
    char comma;

    std::ifstream file;
    file.open(filePath);

    if (file.is_open())
    {
        while (file.good())
        {
            file >> next;

            file >> comma;
        }
    }
    else
    {
        file.close();
        
        exit(1);
    }
    
    file.close();

    return;
}