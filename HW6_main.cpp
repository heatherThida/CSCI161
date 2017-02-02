#include <iostream>
#include "bst.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(NULL));

	int N(1000);
	for (int n = 1; n <= N; ++n)
	{
		vector<int> v;
		for (int i = 1; i <= N; ++i)
			v.push_back(i);

		random_shuffle(v.begin(), v.end());

		bst<int> t;
		for (auto e: v)
			t.insert(e);

		for (int i = 1; i < N; ++i)
			if (t.successor(i) !=  i+1)
			{
				cout << "successor of " << i << " = " << t.successor(i) << "!" << endl;
				cout << "FAILED!" << endl;
				return 1;
			}
	}

	cout << "PASSED" << endl;
	return 0;
}
