#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string, int> Positions;
    Positions[words[0]] = 0;
    
    const int WordsSize = words.size();
    for(int i = 1;i<WordsSize;++i)
    {
        if(words[i][0] != words[i-1].back() || Positions.find(words[i]) != Positions.end())
        {
            return {(i % n) + 1, (i / n) + 1};
        }
        
        Positions[words[i]] = i;
    }
    
    return {0, 0};
}
