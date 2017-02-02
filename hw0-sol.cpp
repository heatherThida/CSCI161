#include <iostream>
#include <queue>

using namespace std;

// Implementation of the Josephus game using a queue
//
// The winner of this game for 4294967311 = 2^32 + 15 is 31 since the winner is 1 when n is a power of 2
//   and jumps by 2 for when n increases by 1

void josephus(unsigned n)
{
	queue<unsigned> q;
	for (unsigned i = 1; i <= n; ++i)
		q.push(i);

	bool keep(true);
	while (q.size() > 1)
	{
		if (keep)
			q.push(q.front());
		else
			cout << q.front() << " ";
		q.pop();
		keep = !keep;
	}
	
	if (!q.empty())
		cout << endl << "Winner = " << q.front() << endl;
}

int main()
{
	for (unsigned n = 1; n <= 32; ++n)
		josephus(n);

	return 0;
}
		

