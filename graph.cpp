#include "graph.h"
#include <cassert>
#include <algorithm>
#include <queue>
#include <vector>

graph::graph()
{
    _data = std::vector<std::list<std::size_t>>();
}

std::size_t graph::n() const
{
    return _data.size();
}

std::size_t graph::m() const
{
    std::size_t ans(0);

    for (auto l: _data)
        ans += l.size();

    return ans/2;
}

bool graph::is_edge(std::size_t i, std::size_t j) const
{
    assert(i < n() && j < n());
    return (std::find(_data[i].begin(),
                      _data[i].end(), j) != _data[i].end());
}

void graph::add_vertex()
{
    _data.push_back(std::list<std::size_t>());
}


void graph::add_edge(std::size_t i, std::size_t j)
{
    assert(i < n() && j < n() && !is_edge(i, j));
    _data[i].push_front(j);
    _data[j].push_front(i);
}

std::list<std::size_t> graph::adj(std::size_t i) const
{
    assert(i < n());
    return _data[i];
}

bool graph::is_complete() const
{
    return m() == n()*(n()-1)/2;
}

std::ostream & operator << (std::ostream & os,
                            const graph & g)
{
    os << g.n() << " " << g.m() << std::endl;

    for (std::size_t v = 0; v < g.n(); ++v)
    {
        for (auto w: g.adj(v))
            if (v < w)
                os << v << " " << w << std::endl;
    }

    /*
    for (std::size_t v = 0; v < g.n(); ++v)
        for (std::size_t w = v+1; w < g.n(); ++w)
            if (g.is_edge(v, w))
                os << v << " " << w << std::endl;
              */

    return os;
}

std::istream & operator >> (std::istream & is,
                            graph & g)
{
    std::size_t n, m, v, w;
    is >> n >> m;

    for (std::size_t i = 0; i < n; ++i)
        g.add_vertex();

    for (std::size_t i = 0; i < m; ++i)
    {
        is >> v >> w;
        g.add_edge(v, w);
    }

    return is;
}

std::size_t graph::ncc() const
{
    std::vector<bool> visited(n(), false);
    std::size_t ans(0);

    for (std::size_t start = 0; start < n(); ++start)
    {
        if (!visited[start])
        {
            ++ans;

            std::queue<std::size_t> q;
            q.push(start);
            visited[start] = true;

            while (!q.empty())
            {
                std::size_t f = q.front();
                q.pop();
                for (auto e: adj(f))
                    if (!visited[e])
                    {
                        q.push(e);
                        visited[e] = true;
                    }
            }

        }
    }
    return ans;
}

bool graph::is_connected() const
{
    return (ncc() == 1);
}


bool graph::is_acyclic() const
{
    std::vector<bool> visited(n(), false);


    for (std::size_t start = 0; start < n(); ++start)
    {
        if (!visited[start])
        {


            std::queue<std::size_t> q;
            q.push(start);
            visited[start] = true;

            while (!q.empty())
            {
                std::size_t f = q.front();
                q.pop();

                std::size_t count(0);
                for (auto e: adj(f))
                {
                    if (!visited[e])
                    {
                        q.push(e);
                        visited[e] = true;
                    }
                    else
                    {
                        if (++count == 2)
                            return false;
                    }
                }

            }

        }
    }

    return true;
}

bool graph::is_tree() const
{
    return (is_connected() && is_acyclic());
}


bool graph::is_bipartite() const
{
    std::vector<int> color(n(), -1);


    for (std::size_t start = 0; start < n(); ++start)
    {
        if (color[start] == -1)  // not yet visited
        {
            std::queue<std::size_t> q;
            q.push(start);
            color[start] = 0;    // could be 1 too

            while (!q.empty())
            {
                std::size_t f = q.front();
                q.pop();

                for (auto e: adj(f))
                {
                    if (color[e] == -1)
                    {
                        q.push(e);
                        color[e] = 1 - color[f];
                    }
                    else
                    {
                        if (color[e] == color[f])
                            return false;
                    }
                }

            }

        }
    }

    return true;
}
