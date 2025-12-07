#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;
	cin >> T;

	int n = 0;
	cin >> n;

	vector<int> A(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	int m = 0;
	cin >> m;

	vector<int> B(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}

	unordered_map<long long, int> CountMap;
	for (int i = 0; i < n; ++i)
	{
		long long ASum = A[i];
		++CountMap[ASum];

		for (int j = i + 1; j < n; ++j)
		{
			ASum += A[j];
			++CountMap[ASum];
		}
	}

	long long Count = 0;
	for (int i = 0; i < m; ++i)
	{
		long long BSum = B[i];
		Count += CountMap[T - BSum];

		for (int j = i + 1; j < m; ++j)
		{
			BSum += B[j];
			Count += CountMap[T - BSum];
		}
	}

	cout << Count;
}
