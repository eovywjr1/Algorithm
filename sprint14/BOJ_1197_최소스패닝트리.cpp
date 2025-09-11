#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ParentVertexes(10001, 0);

struct EdgeInfo
{
	int Vertex1 = 0, Vertex2 = 0;
	int Cost = 0;
};

int FindParent(const int Vertex)
{
	const int ParentVertex = ParentVertexes[Vertex];

	if (ParentVertex == Vertex)
	{
		return Vertex;
	}

	return ParentVertexes[Vertex] = FindParent(ParentVertex);
}

long long MinSpanningCost = 0;

void Union(const int Vertex1, const int Vertex2, const int Cost)
{
	const int MinVertex = min(Vertex1, Vertex2);
	const int MaxVertex = max(Vertex1, Vertex2);

	const int ParentMinVertex = FindParent(MinVertex);
	const int ParentMaxVertex = FindParent(MaxVertex);

	if (ParentMinVertex != ParentMaxVertex)
	{
		ParentVertexes[ParentMaxVertex] = ParentMinVertex;

		MinSpanningCost += Cost;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V = 0, E = 0;
	cin >> V >> E;

	vector<EdgeInfo> EdgeInfos(E);

	for (int i = 1; i <= V; ++i)
	{
		ParentVertexes[i] = i;
	}

	for (int i = 0; i < E; ++i)
	{
		cin >> EdgeInfos[i].Vertex1 >> EdgeInfos[i].Vertex2 >> EdgeInfos[i].Cost;
	}

	sort(EdgeInfos.begin(), EdgeInfos.end(), [](const EdgeInfo& Lhs, const EdgeInfo& Rhs)
		{
			return Lhs.Cost < Rhs.Cost;
		});

	for (const EdgeInfo& EdgeInfo : EdgeInfos)
	{
		Union(EdgeInfo.Vertex1, EdgeInfo.Vertex2, EdgeInfo.Cost);
	}

	cout << MinSpanningCost;
}
