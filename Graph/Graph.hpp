#pragma once

#include <vector>
#include <iostream>

template<typename V, typename E>
struct Graph
{
    struct Ed : E
    {
        int v;

        Ed(E p, int w) : E{p}, v{w} { }
    };

    struct Ve : V, std::vector<Ed> { };

    std::vector<Ve> g;

    Graph(unsigned n = 0) : g(n) { }

    void edgeDirected(int b, int e, E d = E {})
    {
        g[b].push_back(Ed{d, e});
    }

    void edgeUndirected(int b, int e, E d = E {})
    {
        Ed eg{d, e};
        eg.rev = g[e].size() + (b == e);
        g[b].push_back(eg);
        eg.rev = g[eg.v = b].size() - 1;
        g[e].push_back(eg);
    }
};