#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>

class graph
{
public:
    // constructor
    graph();

    // pre: none
    // post: returns the number of vertices in this graph
    std::size_t n() const;

    // pre: none
    // post: returns the number of edges in this graph
    std::size_t m() const;

    // pre: none
    // post: returns the number of connected components of this graph
    std::size_t ncc() const;

    // pre: none
    // post: returns true iff this graph is connected
    bool is_connected() const;

    // pre: none
    // post: returns true iff this graph has no cycles
    bool is_acyclic() const;

    // pre: none
    // post: returns true iff this graph is an unrooted tree
    bool is_tree() const;

    // pre: none
    // post: returns true iff this graph is bipartite
    bool is_bipartite() const;


    // pre: i, j < n()
    // post: returns true if {i, j} is an edge of this graph
    bool is_edge(std::size_t i, std::size_t ) const;


    // pre: i < n()
    // post: returns a list containing vertices adjacent to i
    //       in NO PARTICULAR ORDER
    std::list<std::size_t> adj(std::size_t i) const;

    // pre: none
    // post: returns true if this graph is complete
    bool is_complete() const;


    // pre: none
    // post: a new vertex with label _data.size()-1 has been
    //       added to this graph
    void add_vertex();


    // pre: i, j < n() & {i, j} is not already an edge
    // post: {i, j} has been added to this graph
    void add_edge(std::size_t i, std::size_t j);

    // pre: {i, j} is an edge of this graph
    // post: {i, j} has been removed from this graph
    void remove_edge(std::size_t i, std::size_t j);




private:
    std::vector<std::list<std::size_t>> _data;
    // invariants:
    // there are _data.size() vertices in this graph
    // _data[i] is a list of vertices adjacent to i
    //  in NO PARTICULAR ORDER
};

std::ostream & operator << (std::ostream &, const graph &);
std::istream & operator >> (std::istream &, graph &);
#endif // GRAPH_H
