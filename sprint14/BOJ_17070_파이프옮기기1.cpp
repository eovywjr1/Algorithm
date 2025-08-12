#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int PossibleMoveCount = 0;
int N = 0;
int House[16][16];

enum class PipeMode
{
	Horizontal,
	Vertical,
	Diagonal
};

struct PipeInfo
{
public:
	PipeInfo(const PipeMode InPipeMode, const pair<int,int> Point)
		: _PipeMode(InPipeMode), i(Point.first), j(Point.second)
	{}

	PipeMode _PipeMode;
	int i, j;
};

pair<int, int> GetOppositePoint(const PipeInfo& Pipe)
{
	switch (Pipe._PipeMode)
	{
	case PipeMode::Horizontal:
	{
		return make_pair(Pipe.i, Pipe.j + 1);
	}
	case PipeMode::Vertical:
	{
		return make_pair(Pipe.i + 1, Pipe.j);
	}
	case PipeMode::Diagonal:
	{
		return make_pair(Pipe.i + 1, Pipe.j + 1);
	}
	default:
		break;
	}

	return pair<int, int>();
}

bool CanMove(const PipeInfo& NextPipe)
{
	const pair<int, int> NextOpposite = GetOppositePoint(NextPipe);
	if (NextOpposite.first >= N || NextOpposite.second >= N)
	{
		return false;
	}

	switch (NextPipe._PipeMode)
	{
	case PipeMode::Horizontal:
	{
		if (House[NextPipe.i][NextPipe.j + 1] == 1)
		{
			return false;
		}
		break;
	}
	case PipeMode::Vertical:
	{
		if (House[NextPipe.i + 1][NextPipe.j] == 1)
		{
			return false;
		}
		break;
	}
	case PipeMode::Diagonal:
	{
		if (House[NextPipe.i][NextPipe.j + 1] == 1 || House[NextPipe.i + 1][NextPipe.j] == 1 || House[NextPipe.i + 1][NextPipe.j + 1] == 1)
		{
			return false;
		}
		break;
	}
	default:
		break;
	}

	return true;
}

queue<PipeInfo> PipeQueue;

void SelectNextPipe(const PipeMode InPipeMode, const pair<int, int> Point)
{
	const PipeInfo NextPipe(InPipeMode, Point);
	if (CanMove(NextPipe))
	{
		PipeQueue.push(NextPipe);
	}
}

void CheckPossibleMove()
{
	PipeQueue.push(PipeInfo(PipeMode::Horizontal, make_pair(0, 0)));

	while (!PipeQueue.empty())
	{
		const PipeInfo CurrentPipe = PipeQueue.front();
		PipeQueue.pop();

		const pair<int, int> OppositePoint = GetOppositePoint(CurrentPipe);
		if (OppositePoint.first == N - 1 && OppositePoint.second == N - 1)
		{
			++PossibleMoveCount;

			continue;
		}

		switch (CurrentPipe._PipeMode)
		{
		case PipeMode::Horizontal:
		{
			SelectNextPipe(PipeMode::Horizontal, OppositePoint);
			SelectNextPipe(PipeMode::Diagonal, OppositePoint);
			break;
		}
		case PipeMode::Vertical:
		{
			SelectNextPipe(PipeMode::Vertical, OppositePoint);
			SelectNextPipe(PipeMode::Diagonal, OppositePoint);
			break;
		}
		case PipeMode::Diagonal:
		{
			SelectNextPipe(PipeMode::Horizontal, OppositePoint);
			SelectNextPipe(PipeMode::Vertical, OppositePoint);
			SelectNextPipe(PipeMode::Diagonal, OppositePoint);
			break;
		}
		default:
			break;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> House[i][j];
		}
	}

	CheckPossibleMove();

	cout << PossibleMoveCount;
}
