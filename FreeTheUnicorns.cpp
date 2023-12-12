#include "Utils.h"
#include "Prim.h"

int main(int argc, char *argv[])
{
    char* filePath = argv[1];
    int vertexCount = atoi(argv[2]);

    std::vector<std::vector<int>> graph = readGraph(filePath, vertexCount);

    std::vector<edge> minSpanTree = prim(graph, vertexCount);

    printMST(minSpanTree);

    return 0;
}