#include <iostream>
#include <vector>

using namespace std;

template <class T>
bool linear_search(const vector<T> & v, int lo, int hi,
                   const T & target)
{
    for (int i = lo; i <= hi; ++i)
        if (v[i] == target)
            return true;

    return false;
}


// pre: input vector is sorted from smallest to largest
// post: return true iff target is in v[lo..hi]
template <class T>
bool binary_search(const vector<T> & v, int lo, int hi,
                   const T & target)
{

    while (lo <= hi)
    {
        int mid = (lo + hi)/2; // lo + (hi - lo)/2
        if (v[mid] == target)
            return true;
        if (v[mid] < target)
            lo = mid+1;
        else
            hi = mid -1;
    }

    return false;

}

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
