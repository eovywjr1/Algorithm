#include <bits/stdc++.h>

using namespace std;

string Instruction = "";
int N =0, M=0;
int R = 0, C = 0;
int K = 0;

void FindDestinationDFS(const int x, const int y, const string InInstruction)
{
    static const vector<int> DirectionX = {1, 0, 0, -1};
    static const vector<int> DirectionY = {0, -1, 1, 0};
    static const vector<char> DirectionStr = {'d', 'l', 'r', 'u'};
    
    if(!Instruction.empty())
    {
        return;
    }
    
    if(InInstruction.length() == K)
    {
        if(x == R && y == C)
        {
            Instruction = InInstruction;
        }
        
        return;
    }
    
    for(int i=0;i<4;++i)
    {
        const int NextX = x + DirectionX[i];
        const int NextY = y + DirectionY[i];
        
        if(NextX < 1 || N < NextX || NextY < 1 || M < NextY)
        {
            continue;
        }
        
        const int NextToDestDistance = abs(NextX-R) + abs(NextY-C);
        const int NextMoveCount = InInstruction.length() + 1;
        if(NextToDestDistance + NextMoveCount > K)
        {
            continue;
        }
        
        if((K - NextMoveCount - NextToDestDistance) % 2 == 1)
        {
            continue;
        }
        
        FindDestinationDFS(NextX, NextY, InInstruction + DirectionStr[i]);
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    N = n;
    M = m;
    R = r;
    C = c;
    K = k;
    
    FindDestinationDFS(x, y, string());
    
    if(Instruction == "")
    {
        return "impossible";
    }
    
    return Instruction;
}
