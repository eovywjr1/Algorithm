#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	for (int index = 0; index < N; ++index)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
			{
				cout << 0;
			}
			else
			{
				cout << pq.top().second;
				pq.pop();
			}
			
			cout << '\n';
		}
		else
		{
			const int tempX = (x < 0) ? x * -1 : x;
			pq.push({ tempX, x });
		}
	}
}
