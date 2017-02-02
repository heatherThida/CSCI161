#include <iostream>
#include "digraph.h"
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    digraph d;
    ifstream is("C:\\Users\\ntran\\d2.txt");

    if (is.fail())
    {
        cout << "Can't open file!" << endl;
        return 1;
    }

    is >> d;
    cout << d << endl;

    cout << d.is_dag() << endl;
    return 0;
}
