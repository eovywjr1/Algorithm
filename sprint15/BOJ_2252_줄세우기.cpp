#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N >> M;

	unordered_map<int, vector<int>> Edges;
	vector<int> InDegree(N + 1, 0);

	for (int i = 0; i < M; ++i)
	{
		int Student1 = 0, Student2 = 0;
		cin >> Student1 >> Student2;

		Edges[Student1].push_back(Student2);
		++InDegree[Student2];
	}

	vector<int> Line;
	Line.reserve(N);

	queue<int> q;

	for (int i = 1; i <= N; ++i)
	{
		if (InDegree[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		const int CurrentStudent = q.front();
		q.pop();

		Line.push_back(CurrentStudent);

		for (const int Edge : Edges[CurrentStudent])
		{
			--InDegree[Edge];
			if (InDegree[Edge] == 0)
			{
				q.push(Edge);
			}
		}
	}

	for (const int Student : Line)
	{
		cout << Student << ' ';
	}
}
