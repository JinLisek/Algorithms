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

    void bfs(int s)
    {
        for(auto& v : g)
            v.t = v.s = -1;

        g[s].t = 0;

        int qu[g.size()];
        int b;
        int e;

        qu[b = e = 0] = s;

        while(b <= e)
        {
            s = qu[b++];

            for(const auto& v : g[s])
            {
                if(g[v.v].t == -1)
                {
                    g[qu[++e] = v.v].t = g[s].t + 1;
                    g[v.v].s = s;
                }
            }
        }
    }

};