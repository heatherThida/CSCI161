#ifndef BTNODE_H
#define BTNODE_H

#include <cstdlib>
#include <cassert>

template <class T>
class btnode
{
public:
    // pre: none
    // post: creates a btnode initialized with init_data (default to T())
    //       init_left (default to nullptr), and init_right (default
    //       to nullptr)
    btnode(const T & init_data = T(),
           btnode * init_left = nullptr,
           btnode * init_right = nullptr)
    {
        _data = init_data;
        _left = init_left;
        _right = init_right;
    }

    // pre: none
    // post: returns a constant reference to object in _data
    const T & data() const
    {
        return _data;
    }

    T & data()
    {
        return _data;
    }

    // pre: none
    // post: returns a (constant) pointer to left/right child
    const btnode *left() const
    {
        return _left;
    }

    btnode * & left()
    {
        return _left;
    }

    const btnode *right() const
    {
        return _right;
    }

    btnode * & right()
    {
        return _right;
    }

    bool is_leaf() const
    {
        return (_left == nullptr && _right == nullptr);
    }

private:
    T _data;
    btnode * _left;
    btnode * _right;
    // invariants:
    //  _data holds data stored in this btnode
    //  _left and _right are pointers to the roots of
    //   left and right subtrees
};


template <class T>
void tree_clear(btnode<T> * & root)
{
    if (root == nullptr)
        return;
    tree_clear(root->left());
    tree_clear(root->right());
    delete root;
    root = nullptr;
}

template <class T>
std::size_t tree_size(const btnode<T> * root)
{
    if (root == nullptr)
        return 0;
    return tree_size(root->left()) + 1 + tree_size(root->right());
}

template <class T>
btnode<T> * tree_copy(const btnode<T> * root)
{
    if (root == nullptr)
        return nullptr;

    T value = root->data();
    return new btnode<T> (value,
                          tree_copy(root->left()),
                          tree_copy(root->right()));
}

template <class T>
int tree_height(const btnode<T> * root)
{
    if (root == nullptr)
        return -1;

    return 1 + std::max(tree_height(root->left()),
                        tree_height(root->right()));

}


template <class T>
int tree_leaves(const btnode<T> * root)
{
    if (root == nullptr)
        return 0;

    if (root->is_leaf())
        return 1;

    return tree_leaves(root->left()) + tree_leaves(root->right());


}

template <class T>
void inorder(const btnode<T> * root)
{
    if (root != nullptr)
    {
        inorder(root->left());
        std::cout << root->data() << " ";
        inorder(root->right());
    }
}

template <class T>
void preorder(const btnode<T> * root)
{
    if (root != nullptr)
    {

        std::cout << root->data() << " ";
        preorder(root->left());
        preorder(root->right());
    }
}

template <class T>
void postorder(const btnode<T> * root)
{
    if (root != nullptr)
    {


        postorder(root->left());
        postorder(root->right());
        std::cout << root->data() << " ";
    }
}

template <class T>
void tree_print(std::ostream & os,
                const btnode<T> * root, int level)
{
    if (root == nullptr)
        return;

    tree_print(os, root->right(), level+1);
    for (int k = 0; k < level*4; ++k)
        os << " ";
    os << root->data() << std::endl;
    tree_print(os, root->left(), level+1);
}

// assume keys are distinct
template <class T>
void bst_insert(btnode<T> * & root, const T & entry)
{
    if (root == nullptr)
        root = new btnode<T>(entry);
    else if (root->data() > entry)
        bst_insert(root->left(), entry);
    else
        bst_insert(root->right(), entry);
}

template <class T>
bool bst_find(const btnode<T> * root, const T & target)
{
    if (root == nullptr)
        return false;
    if (root->data() == target)
        return true;
    if (root->data() > target)
        return bst_find(root->left(), target);
    else
        return bst_find(root->right(), target);
}

template <class T>
T bst_delete_max(btnode<T> * & root)
{
    assert(root != nullptr);
    if (root->right() != nullptr)
        return bst_delete_max(root->right());

    T ans = root->data();
    btnode<T> * removeptr = root;
    root = root->left();
    delete removeptr;
    return ans;
}

template <class T>
void bst_delete(btnode<T> * & root, const T & target)
{

    if (root == nullptr)
        return;

    if (root->data() > target)
        bst_delete(root->left(), target);
    else if (root->data() < target)
        bst_delete(root->right(), target);
    else if (root->left() == nullptr)
    {
        btnode<T> * removeptr = root;
        root = root->right();
        delete removeptr;

    }
    else
        root->data() = bst_delete_max(root->left());
}

template <class T>
T bst_min(const btnode<T> * root)
{
    assert(root != nullptr);
    if (root->left() == nullptr)
        return root->data();
    else
        return bst_min(root->left());
}

template <class T>
T bst_max(const btnode<T> * root)
{
	assert(root != nullptr);
	if (root->right() == nullptr)
		return root->data();
	return bst_max(root->right());
}

template <class T>
T bst_successor(const btnode<T> * root, const T & target)
{
	if (root->data() == target)
	{
		if (root->right() != nullptr)
			return bst_min(root->right());
		else
			return target;  
	}

	if (root->data() > target)
	{
		T ans = bst_successor(root->left(), target);
		if (ans == target)
			ans = root->data();
		return ans;
	}
	else
		return bst_successor(root->right(), target);
}
		

#endif // BTNODE_H
