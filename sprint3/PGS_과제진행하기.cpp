#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int convertToMinute(string time){
    const int hour = (time[0] - '0') * 10 + time[1] - '0';
    const int minute = (time[3] - '0') * 10 + time[4] - '0';
    
    return hour * 60 + minute;
}

bool compare(vector<string>& a, vector<string>& b){
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string,int>> remainPlanStack;
    
    sort(plans.begin(), plans.end(), compare);
    
    const int plansSize = plans.size();
    for(int index=0;index<plansSize-1;++index){
        const int planTime = convertToMinute(plans[index][1]);
        const int nextPlanTime = convertToMinute(plans[index+1][1]);
        int remainTimeToNextPlan = nextPlanTime - planTime;
        
        const int playTime = stoi(plans[index][2]);
        if(playTime <= remainTimeToNextPlan){
            answer.push_back(plans[index][0]);
            remainTimeToNextPlan -= playTime;
            
            while(0<remainTimeToNextPlan && remainPlanStack.empty() == false){
                pair<string,int> remainPlan = remainPlanStack.top();
                remainPlanStack.pop();
                
                const int remainPlanRemainTime = remainPlan.second - remainTimeToNextPlan;
                
                if(remainPlanRemainTime <= 0)
                    answer.push_back(remainPlan.first);
                else
                    remainPlanStack.push({remainPlan.first, remainPlanRemainTime});
                
                remainTimeToNextPlan -= remainPlan.second;
            }
        }
        else{
            remainPlanStack.push({plans[index][0], playTime-remainTimeToNextPlan});
        }
    }
    
    answer.push_back(plans[plansSize-1][0]);
    
    while(remainPlanStack.empty() == false){
        const pair<string,int> remainPlan = remainPlanStack.top();
        remainPlanStack.pop();
                
        answer.push_back(remainPlan.first);
    }
    
    return answer;
}
