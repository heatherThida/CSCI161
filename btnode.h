#include <iostream>

template <class Item>
class bt_node
{
     public:
          bt_node(const Item & init_data = Item(),
                  bt_node * init_left = NULL,
                  bt_node * init_right = NULL)
          {
                  data_field = init_data;
                  left_field = init_left;
                  right_field = init_right;
          }

          const Item & data () const   { return data_field; }
          Item & data ()               { return data_field; }
          const bt_node *left() const  { return left_field; }
          bt_node  * & left()          { return left_field; }
          const bt_node *right() const { return right_field; }
          bt_node * & right()          { return right_field; }

          void set_data(const Item & new_data) { data_field = new_data; }
          void set_left(bt_node * new_left)    { left_field = new_left; }
          void set_right(bt_node * new_right)  { right_field = new_right; }

          bool is_leaf() const        
          {
                return (left_field == NULL && right_field == NULL); 
          }

     private:
                Item data_field;
                bt_node *left_field;
                bt_node *right_field; 
};

template <class Item>
void tree_clear(bt_node<Item> * & root_ptr)
{
     if (root_ptr != NULL)
     {
           tree_clear(root_ptr->left());
           tree_clear(root_ptr->right());
           delete root_ptr;
           root_ptr = NULL;
     }
}

template <class Item>
bt_node<Item> * tree_copy(const bt_node<Item> * root_ptr)
{
     bt_node<Item> * l_ptr,  * r_ptr;
  
     if (root_ptr == NULL)
           return NULL;
     l_ptr = tree_copy(root_ptr->left());
     r_ptr = tree_copy(root_ptr->right());
     return new bt_node<Item>(root_ptr->data(), l_ptr, r_ptr);
}

template <class Item>
std::size_t tree_size(const bt_node<Item> * root_ptr)
{
     if (root_ptr == NULL)
         return 0;
     return (1 + tree_size(root_ptr->left()) + tree_size(root_ptr->right()));
}

template <class Process, class BTNode>
void preorder(Process f, BTNode * node_ptr)
{
     if (node_ptr != NULL)
     {
           f(node_ptr->data());
           preorder(f, node_ptr->left());
           preorder(f, node_ptr->right());
     }
}

template <class Process, class BTNode>
void postorder(Process f, BTNode * node_ptr)
{
     if (node_ptr != NULL)
     {
           postorder(f, node_ptr->left());
           postorder(f, node_ptr->right());
           f(node_ptr->data());
     }
}

template <class Process, class BTNode, class SizeType>
void inorder(Process f, BTNode * node_ptr, SizeType level)
{
     if (node_ptr != NULL)
     {
          
           inorder(f, node_ptr->right(), level+1);
           f(node_ptr->data(), level);
           inorder(f, node_ptr->left(), level+1);
     }
}

