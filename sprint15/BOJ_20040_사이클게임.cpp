#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> ParentPoints;

int GetParent(const int Point)
{
	if (Point == ParentPoints[Point])
	{
		return Point;
	}

	return ParentPoints[Point] = GetParent(ParentPoints[Point]);
}

bool Union(const int Point1, const int Point2)
{
	const int MinPoint = min(Point1, Point2);
	const int MaxPoint = max(Point1, Point2);

	const int ParentMinPoint = GetParent(MinPoint);
	const int ParentMaxPoint = GetParent(MaxPoint);

	if (ParentMinPoint == ParentMaxPoint)
	{
		return false;
	}

	ParentPoints[ParentMaxPoint] = ParentMinPoint;

	return true;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	ParentPoints.resize(n);

	for (int i = 0; i < n; ++i)
	{
		ParentPoints[i] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		int Point1 = 0, Point2 = 0;
		cin >> Point1 >> Point2;

		if (!Union(Point1, Point2))
		{
			cout << i + 1;
			return 0;
		}
	}

	cout << 0;
}
