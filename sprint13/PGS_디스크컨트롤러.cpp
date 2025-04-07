#include <bits/stdc++.h>

using namespace std;

struct JobInfo
{
public:
    JobInfo(int InRequestTime, int InJobTime, int InJobIndex)
        : RequestTime(InRequestTime),
        JobTime(InJobTime),
        JobIndex(InJobIndex)
        {}
    
    bool operator>(const JobInfo& Rhs) const
    {
        if(JobTime != Rhs.JobTime)
        {
            return JobTime > Rhs.JobTime;
        }
        
        if(RequestTime != Rhs.RequestTime)
        {
            return RequestTime > Rhs.RequestTime;
        }
        
        return JobIndex > Rhs.JobIndex;
    }
    
    int RequestTime = 0, JobTime = 0, JobIndex = 0;
};

priority_queue<JobInfo, vector<JobInfo>, greater<JobInfo>> DiskController;
int AllTurnAroundTime = 0;
int CurrentTime = 0;

void ProcessJob()
{
    JobInfo CurrentJobInfo = DiskController.top();
    DiskController.pop();
        
    CurrentTime += CurrentJobInfo.JobTime;
    AllTurnAroundTime += CurrentTime - CurrentJobInfo.RequestTime;
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    const int jobsSize = jobs.size();
    int JobIndex = 0;
    
    while(JobIndex < jobsSize)
    {
        while(JobIndex < jobsSize && jobs[JobIndex][0] <= CurrentTime)
        {
            DiskController.push(JobInfo(jobs[JobIndex][0], jobs[JobIndex][1], JobIndex));
            ++JobIndex;
        }
        
        if(DiskController.empty())
        {
            DiskController.push(JobInfo(jobs[JobIndex][0], jobs[JobIndex][1], JobIndex));
            CurrentTime = jobs[JobIndex][0];
            ++JobIndex;
        }
        
        ProcessJob();
    }
    
    while(!DiskController.empty())
    {
        ProcessJob();
    }
    
    return static_cast<int>(AllTurnAroundTime / jobs.size());
}
