#include <bits/stdc++.h>

using namespace std;
using coordinate = pair<int,int>;

bool checkIsolationPartition(const vector<string>& place, const coordinate partitionCoordinate)
{
    queue<pair<coordinate, int>> q; 
    vector<vector<bool>> visited(5, vector<bool>(5,false));
    q.push({partitionCoordinate,0});
    visited[partitionCoordinate.first][partitionCoordinate.second] = true;
    
    const int dirI[4] = {-1, 1, 0, 0};
    const int dirJ[4] = {0,0, -1, 1};
    
    while(q.empty() == false)
    {
        pair<coordinate, int> currentPosition = q.front();
        q.pop();
        
        if(currentPosition.second >= 2)
        {
            continue;
        }
        
        for(int index=0;index<4;++index)
        {
            const int nextI = currentPosition.first.first + dirI[index];
            const int nextJ = currentPosition.first.second + dirJ[index];
            
            if(nextI < 0 || nextI >= 5 || nextJ < 0 || nextJ >= 5 || visited[nextI][nextJ])
            {
                continue;
            }
            
            if(place[nextI][nextJ] == 'P')
            {
                return false;
            }
            else if(place[nextI][nextJ] == 'O')
            {
                q.push({{nextI,nextJ}, currentPosition.second + 1});
                visited[nextI][nextJ] = true;
            }
        }
    }
    
    return true;
}

bool checkIsolationPlace(const vector<string>& place)
{
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            if(place[i][j] == 'P')
            {
                if(checkIsolationPartition(place, {i,j}) == false)
                {
                    return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(const vector<string>& place : places)
    {
        if(checkIsolationPlace(place))
        {
            answer.emplace_back(1);
        }
        else
        {
            answer.emplace_back(0);
        }
    }
    
    return answer;
}
