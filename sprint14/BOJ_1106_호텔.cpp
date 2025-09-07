#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

int main()
{
	int C = 0, N = 0;
	cin >> C >> N;
	int MaxNumber = C + 100;

	vector<int> CostForCustomers(MaxNumber + 1, INT_MAX);

	for (int i = 0; i < N; ++i)
	{
		int Cost = 0, Customer = 0;
		cin >> Cost >> Customer;

		CostForCustomers[Customer] = min(CostForCustomers[Customer], Cost);

		for (int j = Customer + 1; j <= MaxNumber; ++j)
		{
			if (CostForCustomers[j - Customer] != INT_MAX)
			{
				CostForCustomers[j] = min(CostForCustomers[j], CostForCustomers[j - Customer] + Cost);
			}
		}
	}

	int MinCostC = INT_MAX;

	for (int i = C; i <= MaxNumber; ++i)
	{
		if (CostForCustomers[i] != INT_MAX)
		{
			MinCostC = min(MinCostC, CostForCustomers[i]);
		}

	}

	cout << MinCostC;
}
