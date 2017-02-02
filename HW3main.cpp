#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	priority_queue<int> q;

	int N(10000);

	cout << "This will take a few minutes ... " << endl;
	for (int j = 0; j <= N; ++j)
	{
		vector<int> v;
		for (int i = 1; i <= N; ++i)
			v.push_back(i);
		random_shuffle(v.begin(), v.end());

		for (int i = 0; i < N; ++i)
			q.push(v[i]);

		int k = N;
		while (!q.empty())
		{
			v[--k] = q.front();
			q.pop();
		}
		if (!is_sorted(v.begin(), v.end()))
		{
			cout << "FAILED!" << endl;
			return 1;
		}
	}
	cout << "PASSED!" << endl;

	return 0;

}
