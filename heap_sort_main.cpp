#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void fix_heap(vector<T> & v, int r, int n)
{
    while (2*r + 1 < n)
    {
        // left child exists
        int c = 2*r+1;
        if (c + 1 < n && v[c] < v[c+1] )
            ++c;
        if (!(v[r] < v[c]))
            break;
        swap(v[r], v[c]);
        r = c;

    }
}

template <class T>
void make_heap(vector<T> & v)
{
    for(int r = v.size()/2 -1; r >= 0; --r)
        fix_heap(v, r, v.size());

}

template <class T>
void heap_sort(vector<T> & v)
{
    make_heap(v);
    for (int s = v.size(); s > 1; --s)
    {
        swap(v[0], v[s-1]);
        fix_heap(v, 0, s-1);
    }
}


int main(int argc, char *argv[])
{
    int n = 10;

    for (int j = 1; j <= 10; ++j)
    {
    vector<int> v;

    for (int i = 1; i <= n; ++i)
        v.push_back(i);

    random_shuffle(v.begin(), v.end());

    for (auto e: v)
        cout << e << " ";
    cout << endl;


    heap_sort(v);

    for (auto e: v)
        cout << e << " ";
    cout << endl;
    //return 0;
    }
}
