#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    const int invalidDistance = 100000 * 100 + 1;

    vector<vector<int>> distances(n, vector<int>(n, invalidDistance));

    for (int index = 0; index < n; ++index)
    {
        distances[index][index] = 0;
    }

    for (int index = 0; index < m; ++index)
    {
        int start = 0, end = 0, distance = 0;
        cin >> start >> end >> distance;

        distances[start - 1][end - 1] = min(distances[start - 1][end - 1], distance);
    }

    for (int k = 0; k < n; ++k) // k 는 거쳐가는 정점
    {  
		for (int i = 0; i < n; ++i) // i 는 행 (출발 정점)
        {
            for (int j = 0; j < n; ++j) // j 는 열 (도착 정점)
			{
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (distances[i][j] == invalidDistance)
            {
                cout << 0;
            }
            else
            {
                cout << distances[i][j];
            }

            cout << ' ';
        }

        cout << '\n';
    }
}
