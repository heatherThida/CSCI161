#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

int evaluate_postfix(string input)
{
         istringstream ss(input);
         stack<int> operands;
         int op1, op2;
	 string token;

         
	 while (ss >> token) 
	 {
               switch(token[0])
               {
                      case '+':
                                 op2 = operands.top();
                                 operands.pop();
                                 op1 = operands.top();
                                 operands.pop();
                                 operands.push(op1 + op2);
                                 break;
  

                     case '-':
                                 op2 = operands.top();
                                 operands.pop();
                                 op1 = operands.top();
                                 operands.pop();
                                 operands.push(op1 - op2);
                                 break;

                     case '*':
                                 op2 = operands.top();
                                 operands.pop();
                                 op1 = operands.top();
                                 operands.pop();
                                 operands.push(op1 * op2);
                                 break;

                     case '/':
                                 op2 = operands.top();
                                 operands.pop();
                                 op1 = operands.top();
                                 operands.pop();
                                 operands.push(op1 / op2);
                                 break;
                   case '%':
                                 op2 = operands.top();
                                 operands.pop();
                                 op1 = operands.top();
                                 operands.pop();
                                 operands.push(op1 % op2);
                                 break;
                   default:
                                 operands.push(stod(token));
                                 break;
		}
	 }
         return operands.top();
}

int main()
{
	string postfix;

	postfix = prefix2postfix("+ 3 4");
	cout << postfix << " = " << evaluate_postfix(postfix) << endl;
	postfix = prefix2postfix("+ 3 * 4 5");
	cout << postfix << " = " << evaluate_postfix(postfix) << endl;
	postfix = prefix2postfix("+ * 3 4 5");
	cout << postfix << " = " << evaluate_postfix(postfix) << endl;
	postfix = prefix2postfix("+ + / / 30 6 2 1 * - 5 / 40 8 + 2 3");
	cout << postfix << " = " << evaluate_postfix(postfix) << endl;
	postfix = prefix2postfix("+ / * + 5 3 / 6 2 + 4 2 + - + 1 2 / 6 3 / 6 2");
	cout << postfix << " = " << evaluate_postfix(postfix) << endl;
}
                                 
