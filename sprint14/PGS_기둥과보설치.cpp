#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<bool>>> Grid;
vector<vector<int>> Answer;
int N = 0;

bool CanInstallPillar(const int X, const int Y)
{
    if(N <= Y)
    {
        return false;
    }
    
    return Y == 0 || (X - 1 >= 0 && Grid[Y][X - 1][1]) || Grid[Y][X][1] || Grid[Y - 1][X][0];
}

bool CanInstallBarrage(const int X, const int Y)
{
    if(N <= X || Y <= 0)
    {
        return false;
    }
    
    if(Grid[Y - 1][X][0] || Grid[Y - 1][X + 1][0])
    {
        return true;
    }
    
    return X != 0 && Grid[Y][X - 1][1] && Grid[Y][X + 1][1];
}

void Install(const int X, const int Y, const int Type)
{
    if(Type == 0 && !CanInstallPillar(X,Y))
    {
        return;
    }
    else if(Type == 1 && !CanInstallBarrage(X,Y))
    {
        return;
    }
    
    Grid[Y][X][Type] = true;
}

void Remove(const int X, const int Y, const int Type)
{
    Grid[Y][X][Type] = false;
    
    for(int i=0;i<=N;++i)
    {
        for(int j=0;j<=N;++j)
        {
            if(Grid[i][j][0] && !CanInstallPillar(j, i))
            {
                Grid[Y][X][Type] = true;
                return;
            }
            
            if(Grid[i][j][1] && !CanInstallBarrage(j, i))
            {
                Grid[Y][X][Type] = true;
                return;
            }
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    Grid = vector<vector<vector<bool>>>(n + 1, vector<vector<bool>>(n + 1, vector<bool>(2, false)));
    N = n;
    
    for(const vector<int>& Build : build_frame)
    {
        if(Build[3] == 1)
        {
            Install(Build[0], Build[1], Build[2]);
        }
        else
        {
            Remove(Build[0], Build[1], Build[2]);
        }
    }
    
    for(int i=0;i<=N;++i)
    {
        for(int j=0;j<=N;++j)
        {
            for(int k=0;k<2;++k)
            {
                if(Grid[i][j][k])
                {
                    Answer.push_back({j,i,k});
                }
            }
        }
    }
    
    sort(Answer.begin(), Answer.end());
    
    return Answer;
}
