#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    set<string> s;
    unordered_set<string> t;

    s.insert("hello");
    s.insert("world");
    s.insert("ant");

    for (auto e: s)
        cout << e << endl;

    t.insert("hello");
    t.insert("world");
    t.insert("ant");

    sort(s.begin(), s.end());

    for (auto e: t)
        cout << e << endl;
    return 0;
}
