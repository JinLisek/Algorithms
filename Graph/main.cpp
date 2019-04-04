#include "Graph.hpp"
#include "GraphWriter.hpp"

struct Empty { };

int main()
{
    unsigned numOfVertices = 0;
    unsigned numOfEdges = 0;

    std::cout << "Num of vertices in graph: ";
    std::cin >> numOfVertices;

    std::cout << "Num of edges in graph: ";
    std::cin >> numOfEdges;

    Graph<Empty, Empty> graph {numOfVertices};

    for(unsigned i = 0; i < numOfEdges; ++i)
    {
        unsigned edgeStart = 0;
        unsigned edgeEnd = 0;

        std::cout << i + 1 << " (out of " << numOfEdges << ") edge start: ";
        std::cin >> edgeStart;

        std::cout << i + 1 << " (out of " << numOfEdges << ") edge end: ";
        std::cin >> edgeEnd;

        graph.edgeDirected(edgeStart, edgeEnd);
    }

    writeGraph(graph);

    return 0;
}