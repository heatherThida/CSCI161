#include <iostream>
#include "otable.h"

using namespace std;

std::size_t h(const int & n)
{
    return n;
}

int main(int argc, char *argv[])
{
    otable<int, 101, h> t;
    cout << t.size() << endl;

    return 0;
}
