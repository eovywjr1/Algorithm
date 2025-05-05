#include <iostream>
#include <vector>
#include <map>

using namespace std;

int MatrixSize = 0;
long long SqureCount = 0;

struct Matrix
{
public:
	Matrix()
	{
		Values.resize(MatrixSize);

		for (int Index = 0; Index < MatrixSize; ++Index)
		{
			Values[Index].resize(MatrixSize);
		}
	}

	Matrix operator*(const Matrix& rhs)
	{
		Matrix result;

		for (int i = 0; i < MatrixSize; ++i)
		{
			for (int j = 0; j < MatrixSize; ++j)
			{
				for (int k = 0; k < MatrixSize; ++k)
				{
					result.Values[i][j] += (this->Values[i][k] * rhs.Values[k][j]) % 1000;
				}

				result.Values[i][j] %= 1000;
			}
		}

		return result;
	}

	vector<vector<int>> Values;
};

map<long long, Matrix> SquareMatrixes;

Matrix Square(const Matrix& BaseMatrix, long long TempSquareCount)
{
	if (SquareMatrixes.find(TempSquareCount) != SquareMatrixes.end())
	{
		return SquareMatrixes[TempSquareCount];
	}

	const long long MidTempSquareCount = TempSquareCount / 2;
	Matrix LeftMatrix = Square(BaseMatrix, MidTempSquareCount);
	Matrix RightMatrix = Square(BaseMatrix, TempSquareCount - MidTempSquareCount);

	const Matrix Result = LeftMatrix * RightMatrix;
	SquareMatrixes[TempSquareCount] = Result;

	return Result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> MatrixSize >> SqureCount;

	Matrix BaseMatrix;
	
	for (int i = 0; i < MatrixSize; ++i)
	{
		for (int j = 0; j < MatrixSize; ++j)
		{
			cin >> BaseMatrix.Values[i][j];
		}
	}
	
	SquareMatrixes[1] = BaseMatrix;

	const Matrix Result = Square(BaseMatrix, SqureCount);

	for (int i = 0; i < MatrixSize; ++i)
	{
		for (int j = 0; j < MatrixSize; ++j)
		{
			cout << Result.Values[i][j] % 1000 << ' ';
		}

		cout << '\n';
	}
}
