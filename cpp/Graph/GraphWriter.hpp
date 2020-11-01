#pragma once

#include "Graph.hpp"

template<typename V, typename E>
void writeGraph(Graph<V, E> graph)
{
    for(unsigned x = 0; x < graph.g.size(); ++x)
    {
        std::cout << x << ":";

        for(const auto& v : graph.g[x])
            std::cout << " " << v.v;

        std::cout << std::endl;
    }
}