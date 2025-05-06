#include <bits/stdc++.h>

using namespace std;

const int StartTime = 9 * 60;

string solution(int n, int t, int m, vector<string> timetable) {
    const int TimeTableSize = timetable.size();
    vector<int> TimeTable(TimeTableSize);
    
    for(int Index = 0; Index < TimeTableSize; ++Index)
    {
        const string& Time = timetable[Index];
        TimeTable[Index] = stoi(Time.substr(0,2)) * 60 + stoi(Time.substr(3,2));
    }
    
    sort(TimeTable.begin(), TimeTable.end());
    
    int LastCrewIndex = -1;
    int CurrentTime = StartTime;
    int ConeTime = 0;
    
    for(int BusIndex = 0; BusIndex < n; ++BusIndex, CurrentTime += t)
    {
        int RemainSeat = m;
        
        for(int Index = LastCrewIndex + 1; Index < TimeTableSize && TimeTable[Index] <= CurrentTime && RemainSeat > 0; ++Index)
        {
            LastCrewIndex = Index;
            --RemainSeat;
        }
        
        if(BusIndex == n - 1)
        {
            if(RemainSeat == 0)
            {
                ConeTime = TimeTable[LastCrewIndex] - 1;
            }
            else
            {
                ConeTime = CurrentTime;
            }
        }
    }
    
    string answer;
    answer += ConeTime / 60 / 10 + '0';
    answer += ConeTime / 60 % 10 + '0';
    answer += ":";
    answer += ConeTime % 60 / 10 + '0';
    answer += ConeTime % 60 % 10 + '0';
    
    return answer;
}
