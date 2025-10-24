#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> Graph;
vector<int> SubTreeCounts;
vector<bool> Visited;

int PostTravel(int Node)
{
	Visited[Node] = true;

	for (const int& NextNode : Graph[Node])
	{
		if (!Visited[NextNode])
		{
			SubTreeCounts[Node] += PostTravel(NextNode);
		}
	}

	return SubTreeCounts[Node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0, R = 0, Q = 0;
	cin >> N >> R >> Q;

	Graph = vector<vector<int>>(N + 1);
	SubTreeCounts = vector<int>(N + 1, 1);
	Visited = vector<bool>(N + 1, false);

	for (int i = 0; i < N - 1; ++i)
	{
		int U = 0, V = 0;
		cin >> U >> V;

		Graph[U].push_back(V);
		Graph[V].push_back(U);
	}

	PostTravel(R);

	for (int i = 0; i < Q; ++i)
	{
		int QueryNode = 0;
		cin >> QueryNode;

		cout << SubTreeCounts[QueryNode] << '\n';
	}
}
