#include <iostream>
#include <vector>

using namespace std;


template <class T>
void merge(vector<T> &v, int lo, int mid, int hi)
{
    int n = hi - lo + 1;  // number of elements
    vector<T> temp(n);

    int i = lo;  // smallest of left half
    int j = mid+1; // smallest of right half

    for (int k = 0; k < n; ++k)
    {
        if (i > mid)
            temp[k] = v[j++];
        else if (j > hi)
            temp[k] = v[i++];
        else if (v[j] < v[i])
            temp[k] = v[j++];
        else
            temp[k] = v[i++];
    }

    std::copy(temp.begin(), temp.end(), v.begin() + lo); // copy sorted result back to v

}

template <class T>
void mergesort(vector<T> & v, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = (lo + hi) / 2;
        mergesort(v, lo, mid);
        mergesort(v, mid+1, hi);
        merge(v, lo, mid, hi);
    }
}

int main(int argc, char *argv[])
{
    vector<int> v {1, 3, 2, 4, 5, 6};
    mergesort(v, 0, 5);

    for (auto e: v)
        cout << e << " ";
    cout << endl;

    return 0;
}
