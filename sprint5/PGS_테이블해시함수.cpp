#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int colIndex;

bool compare(vector<int>& a, vector<int>& b){
    if(a[colIndex]==b[colIndex])
        return b[0] < a[0];
    
    return a[colIndex] < b[colIndex];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    colIndex = col - 1;
    
    sort(data.begin(), data.end(), compare);
    
    for(int index=row_begin-1;index<row_end;++index){
        int modSum = 0;
        
        const int columnSize = data[index].size();
        for(int j = 0; j<columnSize;++j){
            modSum += data[index][j] % (index+1);
        }
        
        answer ^= modSum;
    }
    
    return answer;
}
