#include <bits/stdc++.h>

using namespace std;

bool checkIsolation(const vector<string>& place)
{
    vector<pair<int,int>> partitions;
    
    for(int i=0;i<5;++i)
    {
        for(int j=0;j<5;++j)
        {
            if(place[i][j] == 'P')
            {
                partitions.emplace_back(i,j);
            }
        }
    }
    const int partitionsSize = partitions.size();
    for(int i = 0; i < partitionsSize; ++i)
    {
        for(int j = 0; j< partitionsSize; ++j)
        {
            if(i==j)
            {
                continue;
            }
            
            const int distance = abs(partitions[i].first - partitions[j].first) + abs(partitions[i].second - partitions[j].second);
            if(distance == 1)
            {
                return false;
            }
            else if(distance == 2)
            {
                if(partitions[i].first == partitions[j].first || partitions[i].second == partitions[j].second)
                {
                    if(partitions[i].first == partitions[j].first && place[partitions[i].first][(partitions[i].second + partitions[j].second)/2] != 'X')
                    {
                        return false;
                    }
                    if(partitions[i].second == partitions[j].second && place[(partitions[i].first + partitions[j].first)/2][partitions[i].second] != 'X')
                    {
                        return false;
                    }
                }
                else if(place[partitions[i].first][partitions[j].second] != 'X' || place[partitions[j].first][partitions[i].second] != 'X')
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
        if(checkIsolation(place))
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
