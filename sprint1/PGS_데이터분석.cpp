#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sortByIndex = 0;

int getDataIndexByString(string str){
    if(str == "code")
        return 0;
    if(str == "date")
        return 1;
    if(str =="maximum")
        return 2;
    if(str =="remain")
        return 3;
}

bool compare(vector<int> &a, vector<int> &b){
    return a[sortByIndex] < b[sortByIndex];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    const int extIndex = getDataIndexByString(ext);
    
    for(vector<int> eachData : data){
        if(eachData[extIndex] < val_ext)
            answer.push_back(eachData);
    }
    
    sortByIndex = getDataIndexByString(sort_by);
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
