#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> matrix;

int getMinimumNumberFromRotation(const vector<int>& query)
{
    const int x1 = query[0] - 1;
    const int x2 = query[2] - 1;
    const int y1 = query[1] - 1;
    const int y2 = query[3] - 1;
    
    const int dirI[4] = {0, 1, 0, -1};
    const int dirJ[4] = {1, 0, -1, 0};
    
    int i = x1, j = y1, direction = 0;
    int tempNum = matrix[i][j];
    int minNum = INT_MAX;
    
    while(direction < 4)
    {
        swap(matrix[i][j], tempNum);
        minNum = min(minNum, matrix[i][j]);
        
        if((direction == 0 && j == y2) || (direction == 1 && i == x2) || (direction == 2 && j == y1) 
           || (direction == 3 && i == x1))
        {
            ++direction;
        }
        
        if(direction < 4)
        {
            i += dirI[direction];
            j += dirJ[direction];
        }
    }
    
    return minNum;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    matrix.resize(rows);
    for(int index = 0; index < rows; ++index)
    {
        matrix[index].resize(columns);
    }
    
   int num = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
        {
            matrix[i][j] = ++num;
        }
    }
    
    vector<int> answer;
    
    for(const vector<int>& query : queries)
    {
        answer.push_back(getMinimumNumberFromRotation(query));
    }
    
    return answer;
}
