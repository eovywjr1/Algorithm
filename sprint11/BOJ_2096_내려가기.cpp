#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <tuple>
#include <array>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N = 0;
	cin >> N;

	array<array<int, 3>, 2> ScoreDp;

	for (int ScoreJIndex = 0; ScoreJIndex < 3; ++ScoreJIndex)
	{
		cin >> ScoreDp[0][ScoreJIndex];

		ScoreDp[1][ScoreJIndex] = ScoreDp[0][ScoreJIndex];
	}

	for (int ScoreIIndex = 1; ScoreIIndex < N; ++ScoreIIndex)
	{
		array<int, 3> Scores;

		for (int ScoreJIndex = 0; ScoreJIndex < 3; ++ScoreJIndex)
		{
			cin >> Scores[ScoreJIndex];
		}

		array<int, 3> TempScoreDp;

		TempScoreDp[0] = max(ScoreDp[0][0] + Scores[0], ScoreDp[0][1] + Scores[0]);
		TempScoreDp[1] = max(ScoreDp[0][0] + Scores[1], max(ScoreDp[0][1] + Scores[1], ScoreDp[0][2] + Scores[1]));
		TempScoreDp[2] = max(ScoreDp[0][1] + Scores[2], ScoreDp[0][2] + Scores[2]);
		ScoreDp[0] = TempScoreDp;

		TempScoreDp[0] = min(ScoreDp[1][0] + Scores[0], ScoreDp[1][1] + Scores[0]);
		TempScoreDp[1] = min(ScoreDp[1][0] + Scores[1], min(ScoreDp[1][1] + Scores[1], ScoreDp[1][2] + Scores[1]));
		TempScoreDp[2] = min(ScoreDp[1][1] + Scores[2], ScoreDp[1][2] + Scores[2]);
		ScoreDp[1] = TempScoreDp;
	}

	const int MaxScore = max(ScoreDp[0][0], max(ScoreDp[0][1], ScoreDp[0][2]));
	const int MinScore = min(ScoreDp[1][0], min(ScoreDp[1][1], ScoreDp[1][2]));

	cout << MaxScore << '\n' << MinScore;
}
