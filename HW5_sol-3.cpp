#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include "btnode.h"

using namespace std;

// pre: exp is a postfix expression involving double op/operands
// post: value of this expression

btnode<string> * expression_tree(const string & exp)
{
  istringstream ss(exp);
  string token;
  stack<btnode<string> *> st;
  btnode<string> * left,  * right;


  if (exp.size() == 0)
	  return nullptr;

  while (ss >> token)
    {
      switch(token[0])
        {
        case '+':
	  right = st.top();
	  st.pop();
	  left = st.top();
	  st.pop();
	  st.push(new btnode<string>("+", left, right));
	  break;

        case '-':
	  right = st.top();
	  st.pop();
	  left = st.top();
	  st.pop();
	  st.push(new btnode<string>("-", left, right));
	  break;

        case '*':
	  right = st.top();
	  st.pop();
	  left = st.top();
	  st.pop();
	  st.push(new btnode<string>("*", left, right));
	  break;

        case '/':
	  right = st.top();
	  st.pop();
	  left = st.top();
	  st.pop();
	  st.push(new btnode<string>("/", left, right));
	  break;

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
	  st.push(new btnode<string>(token));
	  break;

        default:
	  break;
        }

    }

  return st.top();

}

int main(int argc, char *argv[])
{

  btnode<string> * t(nullptr);

  t = expression_tree("");
  tree_print(cout, t, 0);
  postorder(t);
  tree_clear(t);
  cout << endl << "-----------" << endl;

  t = expression_tree(string("3 4 + "));
  tree_print(cout, t, 0);
  postorder(t);
  tree_clear(t);
  cout << endl << "-----------" << endl;

  t = expression_tree(string("3 4 5 * +"));
  cout << t << endl;
  tree_print(cout, t, 0);
  postorder(t);
  tree_clear(t);
  cout << endl << "-----------" << endl;

  t = expression_tree(string("3 4 * 5 +"));
  tree_print(cout, t, 0);
  postorder(t);
  tree_clear(t);
  cout << endl << "-----------" << endl;

  t = expression_tree(string("30 6 / 2 / 1 + 5 40 8 / - 2 3 + * +"));
  tree_print(cout, t, 0);
  postorder(t);
  tree_clear(t);
  cout << endl << "-----------" << endl;

  t = expression_tree(string("5 3 + 6 2 / * 4 2 + / 1 2 + 6 3 / - 6 2 / + +"));
  tree_print(cout, t, 0);
  postorder(t);
  tree_clear(t);
  cout << endl << "-----------" << endl;

  return 0;
}

