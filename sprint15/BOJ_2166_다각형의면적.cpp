#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<pair<long long, long long>> Points(N + 1);
	for (int i = 0; i < N; ++i)
	{
		int x = 0, y = 0;
		cin >> x >> y;
		Points[i] = make_pair(x, y);
	}

	Points[N] = Points[0];

	long long Area = 0;
	for (int i = 0; i < N; ++i)
	{
		Area += (Points[i].first * Points[i + 1].second) - (Points[i + 1].first * Points[i].second);
	}

	printf("%.1f\n", abs(Area) / 2.0);
}
