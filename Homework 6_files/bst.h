#ifndef BST_H
#define BST_H

#include "btnode.h"
#include <cassert>

template <class T>
class bst
{
public:
    // pre: none
    // post: creates an empty bst
    bst()
    {
        _root = nullptr;
    }

    // pre: none
    // post: returns dynamically allocated memory back to OS
    ~bst()
    {
        tree_clear(_root);
    }

    std::size_t size() const
    {
        return tree_size(_root);
    }

    void operator=(const bst & source)
    {
        // check for self-assignment
        if (&source == this)
            return;

        tree_clear(_root);
        _root = tree_copy(source._root);
    }

    bool find(const T & target) const
    {
        return bst_find(_root, target);
    }

    void insert(const T & target)
    {
        assert(!find(target));
        bst_insert(_root, target);

    }

    void erase(const T & target)
    {
        assert(find(target));
        bst_delete(_root, target);
    }

    T min() const
    {
        return bst_min(_root);
    }

    T max() const
    {
	    return bst_max(_root);
    }
    
    T successor(const T & target) const
    {
	    assert(find(target) && target != max());
	    return bst_successor(_root, target);
    }


    template <class Z>
    friend std::ostream & operator << (std::ostream &,
                                       const bst<Z> &);
private:
    btnode<T> * _root;
    // invariants:
    // root points to the root node of a binary
    // search tree
};

template <class T>
std::ostream & operator << (std::ostream &os,
                            const bst<T> & t)
{

    tree_print(os, t._root, 0);
    return os;
}

#endif // BST_H
