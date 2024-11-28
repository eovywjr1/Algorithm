#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int width = 0, height = 0;

struct Indices
{
public:
	Indices(int ini, int inj) : i(ini), j(inj) {}
	Indices operator+(const Indices& rhs) const { return Indices(i + rhs.i, j + rhs.j); }
	bool isValid() const
	{
		if (i < 0 || i >= height || j < 0 || j >= width)
		{
			return false;
		}

		return true;
	}

	int i = 0, j = 0;
};

const vector<Indices> directionIndices{ { -1,0 }, { 1,0 }, { 0,-1 }, { 0,1 } };
vector<pair<Indices,bool>> cheezeIndices;
vector<Indices> meltCheezes;

void makeAir(const vector<vector<int>>& airAndCheezeInPaper, vector<vector<bool>>& isExternalAirs, const Indices indices)
{
	if (isExternalAirs[indices.i][indices.j])
	{
		return;
	}

	bool isExternalAir = false;

	for (const Indices& direction : directionIndices)
	{
		const Indices nextIndices = indices + direction;

		if (nextIndices.isValid() == false || isExternalAirs[nextIndices.i][nextIndices.j])
		{
			isExternalAir = true;
			break;
		}
	}

	isExternalAirs[indices.i][indices.j] = isExternalAir;

	if (isExternalAir == false)
	{
		return;
	}

	queue<Indices> AirIndicesQueue;
	AirIndicesQueue.push(indices);

	while (AirIndicesQueue.empty() == false)
	{
		const Indices currentAir = AirIndicesQueue.front();
		AirIndicesQueue.pop();

		for (const Indices& direction : directionIndices)
		{
			const Indices nextIndices = currentAir + direction;

			if (nextIndices.isValid() == false || airAndCheezeInPaper[nextIndices.i][nextIndices.j] == 1 || isExternalAirs[nextIndices.i][nextIndices.j])
			{
				continue;
			}

			isExternalAirs[nextIndices.i][nextIndices.j] = true;
			AirIndicesQueue.push(nextIndices);
		}
	}
}

void findCanMeltCheeze(const vector<vector<bool>>& isExternalAirs)
{
	for (pair<Indices, bool>& cheeze : cheezeIndices)
	{
		if (cheeze.second)
		{
			continue;
		}

		int contactAirCount = 0;

		for (const Indices& direction : directionIndices)
		{
			const Indices nextIndices = cheeze.first+ direction;
			if (nextIndices.isValid() && isExternalAirs[nextIndices.i][nextIndices.j])
			{
				++contactAirCount;
			}
		}

		if (contactAirCount >= 2)
		{
			meltCheezes.push_back(cheeze.first);
			cheeze.second = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> height >> width;

	vector<vector<int>> airAndCheezeInPaper(height, vector<int>(width, false));
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			cin >> airAndCheezeInPaper[i][j];

			if (airAndCheezeInPaper[i][j] == 1)
			{
				cheezeIndices.push_back({ {i,j}, false });
			}
		}
	}

	vector<vector<bool>> isExternalAirs(height, vector<bool>(width, false));
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (airAndCheezeInPaper[i][j] == 0)
			{
				makeAir(airAndCheezeInPaper, isExternalAirs, { i,j });
			}
		}
	}
	
	int time = 0;

	while (true)
	{
		meltCheezes.clear();

		findCanMeltCheeze(isExternalAirs);

		if (meltCheezes.empty())
		{
			break;
		}

		for (const Indices& meltCheeze : meltCheezes)
		{
			makeAir(airAndCheezeInPaper, isExternalAirs, meltCheeze);
		}

		++time;
	}

	cout << time;
}
