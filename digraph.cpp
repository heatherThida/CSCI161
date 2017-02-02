#include "digraph.h"
#include <cassert>
#include <algorithm>
#include <vector>

digraph::digraph()
{
    _data = std::vector<std::list<std::size_t>>();
}

std::size_t digraph::n() const
{
    return _data.size();
}

std::size_t digraph::m() const
{
    std::size_t ans(0);

    for (auto l: _data)
        ans += l.size();

    return ans;
}

bool digraph::is_edge(std::size_t i, std::size_t j) const
{
    assert(i < n() && j < n());
    return (std::find(_data[i].begin(),
                      _data[i].end(), j) != _data[i].end());
}

void digraph::add_vertex()
{
    _data.push_back(std::list<std::size_t>());
}


void digraph::add_edge(std::size_t i, std::size_t j)
{
    assert(i < n() && j < n() && !is_edge(i, j));
    _data[i].push_front(j);
}

std::list<std::size_t> digraph::adj(std::size_t i) const
{
    assert(i < n());
    return _data[i];
}


std::ostream & operator << (std::ostream & os,
                            const digraph & g)
{
    os << g.n() << " " << g.m() << std::endl;

    for (std::size_t v = 0; v < g.n(); ++v)
    {
        for (auto w: g.adj(v))
            os << v << " " << w << std::endl;
    }

    return os;
}

std::istream & operator >> (std::istream & is,
                            digraph & g)
{
    std::size_t n, m, v, w;
    is >> n >> m;

    g = digraph();

    for (std::size_t i = 0; i < n; ++i)
        g.add_vertex();

    for (std::size_t i = 0; i < m; ++i)
    {
        is >> v >> w;
        g.add_edge(v, w);
    }

    return is;
}


void digraph::dfs1(std::size_t start, std::vector<std::size_t> &pre,
                   std::vector<std::size_t> &post, std::size_t &clock, bool & isdag)
{
    pre[start] = clock++;
    for (auto n: adj(start))
    {
        if (pre[n] == 0)   // has not been visited
        {
            std::cout << "(" << start << ", " << n << "): tree" << std::endl;
            dfs1(n, pre, post, clock, isdag);
        }
        else if (post[n] == 0)
        {
            std::cout << "(" << start << ", " << n << "): back" << std::endl;
            isdag = false;
        }
        else if (pre[start] < pre[n])
            std::cout << "(" << start << ", " << n << "): forward" << std::endl;
        else
            std::cout << "(" << start << ", " << n << "): cross" << std::endl;


    }
    post[start] = clock++;
}

bool digraph::is_dag()
{
    std::vector<std::size_t> pre(n(), 0), post(n(), 0);
    std::size_t clock(1);
    bool ans(true);

    for (std::size_t start = 0; start <  n(); ++start)
        if (pre[start] == 0)
            dfs1(start, pre, post, clock, ans);


    std::cout << "pre: ";
    for (auto e: pre)
        std::cout << e << " ";
    std::cout << std::endl;
    std::cout << "post: ";

    for (auto e: post)
        std::cout << e << " ";
    std::cout << std::endl;

    return ans;

}
