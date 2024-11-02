#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    set<string> GemKind;
    for(const string& gem : gems){
        GemKind.insert(gem);
    }
    
    vector<int> Answer;
    if(GemKind.size() == 1){
        Answer.push_back(1);
        Answer.push_back(1);
        
        return Answer;
    }
    
    int FrontIndex = 0;
    int MinBuyLength = INT_MAX-1;
    int MinBuyFrontIndex = 0;
    int MinBuyBackIndex = 0;
    unordered_map<string, int> GemCount;
    ++GemCount[gems[0]];
    
    for(int GemIndex = 1; GemIndex < gems.size(); ++GemIndex){
        ++GemCount[gems[GemIndex]];
        
        while(GemCount[gems[FrontIndex]] > 1){
            --GemCount[gems[FrontIndex]];
            ++FrontIndex;
        }
        
        if(GemKind.size() <= GemCount.size() && GemIndex - FrontIndex + 1 < MinBuyLength){
            MinBuyLength = GemIndex - FrontIndex + 1;    
            MinBuyFrontIndex = FrontIndex;
            MinBuyBackIndex = GemIndex;
        }
    }
    
    Answer.push_back(MinBuyFrontIndex + 1);
    Answer.push_back(MinBuyBackIndex + 1);
    
    return Answer;
}
