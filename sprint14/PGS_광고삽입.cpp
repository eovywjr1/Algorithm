#include <bits/stdc++.h>

using namespace std;

string solution(string play_time, string adv_time, vector<string> logs) {
    const int MaxTime = 59 + 59 * 60 + 99 * 60 * 60;
    vector<long long> CountPerSeconds(MaxTime + 1, 0);
    
    for(const string& Log : logs)
    {
        const int StartTime = stoi(Log.substr(0, 2)) * 60 * 60 + stoi(Log.substr(3, 2)) * 60 + stoi(Log.substr(6, 2));
        const int EndTime = stoi(Log.substr(9, 2)) * 60 * 60 + stoi(Log.substr(12, 2)) * 60 + stoi(Log.substr(15, 2));   
        
        for(int i = StartTime; i < EndTime; ++i)
        {
            ++CountPerSeconds[i];
        }
    }
    
    const int AdvTime = stoi(adv_time.substr(0, 2)) * 60 * 60 + stoi(adv_time.substr(3, 2)) * 60 + stoi(adv_time.substr(6, 2));
    const int PlayTime = stoi(play_time.substr(0, 2)) * 60 * 60 + stoi(play_time.substr(3, 2)) * 60 + stoi(play_time.substr(6, 2));
    
    long long SumCount = 0;
    vector<long long> Accumulate(PlayTime, 0);
    for(int Second = 0; Second < AdvTime; ++Second)
    {
        SumCount += CountPerSeconds[Second];
        Accumulate[Second] = SumCount;
    }
    
    long long MaxSumPlayTime = Accumulate[AdvTime - 1];
    int MaxStartTime = 0;
    
    for(int Second = AdvTime; Second < PlayTime; ++Second)
    {
        SumCount += CountPerSeconds[Second];
        Accumulate[Second] = SumCount;
        
        const long long PeriodSum = Accumulate[Second] - Accumulate[Second - AdvTime];
        if(MaxSumPlayTime < PeriodSum)
        {
            MaxSumPlayTime = PeriodSum;
            MaxStartTime = Second - AdvTime + 1;
        }
    }
    
    const int MaxSeconds = MaxStartTime;
    const int MaxHours = MaxSeconds / 60 / 60;
    const string MaxHoursStr = to_string(MaxHours);
    string Answer = MaxHours < 10 ? "0" + MaxHoursStr : MaxHoursStr;
    Answer += ":";
    
    const int MaxMinutes = MaxSeconds / 60 % 60;
    const string MaxMinutesStr = to_string(MaxMinutes);
    Answer += MaxMinutes < 10 ? "0" + MaxMinutesStr : MaxMinutesStr;
    Answer += ":";
    
    const int MaxSecond = MaxSeconds % 60;
    const string MaxSecondStr = to_string(MaxSecond);
    Answer += MaxSecond < 10 ? "0" + MaxSecondStr : MaxSecondStr;
    
    return Answer;
}
