#include <iostream>
#include "btnode.h"
#include <string>
#include "bst.h"
using namespace std;

int main(int argc, char *argv[])
{
    /*
    btnode<string> *p = new btnode<string>("world");
    p = new btnode<string>("Hello", p);

    cout << p->data() << endl;
    cout << p->left()->data() << endl;
    p->right() = new btnode<string>("test");

    cout << p->right()->data() << endl;

    cout << tree_size(p) << endl;

    btnode<string> * copy = tree_copy(p);
    cout << tree_size(copy) << endl;

    p->data() += "junk";
    cout << p->data() << endl;
    cout << copy->data() << endl;

    tree_clear(p);

    cout << tree_height(p) << endl;
    cout << tree_height(copy) << endl;
    cout << tree_leaves(p) << endl;
    cout << tree_leaves(copy) << endl;

    inorder(copy);
    cout << endl;
    preorder(copy);
    cout << endl;
    postorder(copy);
    cout << endl;

    tree_print(copy, 0);
    */

    /*
    btnode<int> *root(nullptr);

    bst_insert(root, 3);
    bst_insert(root, 1);
    bst_insert(root, 4);
    bst_insert(root, 5);
    bst_insert(root, 2);
    bst_insert(root, 7);
    bst_insert(root, 8);
    bst_insert(root, 6);

    tree_print(root, 0);
    while (true)
    {
        int target;
        cout << "Enter a target: ";
        cin >> target;
        cout << bst_find(root, target) << endl;
    }

    */

    bst<int> t;
    t.insert(3);
    t.insert(1);
    t.insert(4);
    t.insert(2);


    cout << t << endl;

    cout << "Min = " << t.min() << endl;
    t.erase(3);
    cout << t << endl;

    t.erase(2);
    cout << t << endl;

    t.erase(1);
    cout << t << endl;

    t.erase(4);
    cout << t << endl;
    return 0;
}
