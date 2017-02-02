#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include <vector>
#include <list>

class digraph
{
public:
    // constructor
    digraph();

    // pre: none
    // post: returns the number of vertices in this digraph
    std::size_t n() const;

    // pre: none
    // post: returns the number of edges in this digraph
    std::size_t m() const;

    // pre: none
    // post: returns true iff this digraph has no cycles
    bool is_dag();

    // pre: i, j < n()
    // post: returns true if (i, j) is an edge of this digraph
    bool is_edge(std::size_t i, std::size_t j) const;


    // pre: i < n()
    // post: returns a list containing vertices adjacent to i
    //       in NO PARTICULAR ORDER
    std::list<std::size_t> adj(std::size_t i) const;


    // pre: none
    // post: a new vertex with label _data.size()-1 has been
    //       added to this digraph
    void add_vertex();


    // pre: i, j < n() & (i, j) is not already an edge
    // post: (i, j) has been added to this digraph
    void add_edge(std::size_t i, std::size_t j);

    // pre: none
    // post: a DFS has been performed on this digraph
    void dfs();

    // pre: start < n()
    // post: a DFS has been performed starting at vertex start
    void dfs1(std::size_t start, std::vector<std::size_t> & pre,
              std::vector<std::size_t> & post, std::size_t & clock, bool & isdag);




private:
    std::vector<std::list<std::size_t>> _data;
    // invariants:
    // there are _data.size() vertices in this digraph
    // _data[i] is a list of vertices adjacent to i
    //  in NO PARTICULAR ORDER

};

std::ostream & operator << (std::ostream &, const digraph &);
std::istream & operator >> (std::istream &, digraph &);

#endif // DIGRAPH_H
