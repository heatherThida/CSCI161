#include <iostream>
#include "graph.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    graph g;
    ifstream is("c:\\Users\\ntran\\pentagon.txt");
    if (is.fail())
    {
        cout << "Can't open file!" << endl;
        return 1;
    }

    is >> g;

    cout << g << endl;

    for (std::size_t i = 0; i < g.n(); ++i)
    {
        for (auto e: g.adj(i))
            cout << e << " ";
        cout << endl;
    }

    cout << "Number of connected components: " << g.ncc() << endl;
    cout << "Is connected ? " << g.is_connected() << endl;
    cout << "Is acyclic ? " << g.is_acyclic() << endl;
    cout << "Is tree ? " << g.is_tree() << endl;
    cout << "Is bipartite ? " << g.is_bipartite() << endl;
    return 0;
}
