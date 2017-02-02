#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mycount(0);

template <class T>
int partition(vector<T> & v, int lo, int hi)
{
	int i(lo);
	for (int j = lo; j < hi; ++j)
	{
		++mycount;
		if (v[j] < v[hi])
			swap(v[i++], v[j]);
	}

	swap(v[hi], v[i]);
	return i;
}

template <class T>
void quick_sort(vector<T> & v, int lo, int hi)
{
	if (lo < hi)
	{
		int k = partition(v, lo, hi);
		quick_sort(v, lo, k-1);
		quick_sort(v, k+1, hi);
	}
}

int main()
{
	vector<int> v;
	int total(0);

	for (int i = 1; i <= 10; ++i)
		v.push_back(i);

	do
	{
		mycount = 0;
		vector<int> temp(v);
		quick_sort(temp, 0, temp.size()-1);
		if (mycount == v.size()*(v.size()-1)/2)
		{
			for (auto e: v)
				cout << e << " ";
			cout << endl;
			++total;
		}
	} while ( next_permutation(v.begin(), v.end()));

	cout << "total = " << total << endl;

}

