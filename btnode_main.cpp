#include <iostream>
#include "btnode.h"

void print(int i, int level)
{
        for (int k = 0; k < 4*level; ++k)
                std::cout << " ";
        std::cout << i << std::endl;
}


template <class T>
void treeprint(std::ostream & os, bt_node<T> * r, int level)
{
	if (r == nullptr)
		return;
	treeprint(os, r->right(), level+1);
        for (int k = 0; k < 4*level; ++k)
                os << " ";
        os << r->data() << std::endl;
	treeprint(os, r->left(), level+1);
}

template <class T>
std::ostream & operator << (std::ostream & os, bt_node<T> * r)
{
	treeprint(os, r, 0);
	return os;
}

int main()
{
        bt_node<int> *r, *l, *root, *copy;

        r = new bt_node<int>(8);
        r = new bt_node<int>(7, NULL, r);
        r = new bt_node<int>(6, r, NULL);

        l = new bt_node<int>(5);
        l = new bt_node<int>(3, new bt_node<int>(4), l);
        l = new bt_node<int>(2, NULL, l);
        root = new bt_node<int>(1, l, r);

        inorder(print, root, 0);
        std::cout << "size of root = " << tree_size(root) << std::endl;
        copy = tree_copy(root);
        std::cout << "size of copy = " << tree_size(copy) << std::endl;
        tree_clear(root);
        std::cout << "size of root = " << tree_size(root) << std::endl;
        inorder(print, root, 0);
        inorder(print, copy, 0);
	std::cout << "copy = " << copy << std::endl;
	std::cout << "printing tree: " << std::endl;
	std::cout << copy;
}

