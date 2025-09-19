#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<int>> InfoMap;
const int ConditionCount = 4;

void AddInfo(const vector<string>& Conditions, string Condition, const int Count)
{
    if(Count == ConditionCount)
    {
        InfoMap[Condition].push_back(stoi(Conditions[ConditionCount]));
        return;
    }
    
    AddInfo(Conditions, Condition + Conditions[Count], Count + 1);
    AddInfo(Conditions, Condition + "-", Count + 1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    for(const string& Info : info)
    {
        istringstream iss(Info);
        vector<string> Conditions(ConditionCount + 1);
        iss >> Conditions[0] >> Conditions[1] >> Conditions[2] >> Conditions[3] >> Conditions[4];
        
        AddInfo(Conditions, "", 0);
    }
    
    for(auto& Iter : InfoMap)
    {
        sort(Iter.second.begin(), Iter.second.end());
    }

    vector<int> answer;
    answer.reserve(query.size());
    
    for(const string& Query : query)
    {
        istringstream iss(Query);
        vector<string> Conditions(ConditionCount + 1);
        iss >> Conditions[0] >> Conditions[1] >> Conditions[1] >> Conditions[2] >> Conditions[2] >> Conditions[3] >> Conditions[3] >> Conditions[4];
        
        const string Condition = Conditions[0] + Conditions[1] + Conditions[2] + Conditions[3];
        
        if(InfoMap[Condition].empty())
        {
            answer.push_back(0);
            continue;
        }
        
        
        const int Idx = lower_bound(InfoMap[Condition].begin(), InfoMap[Condition].end(), stoi(Conditions[4])) - InfoMap[Condition].begin();
        
        answer.push_back(InfoMap[Condition].size() - Idx);
    }
    
    return answer;
}
