#include <string>
#include <vector>
#include <cmath>

using namespace std;

int calculateSecond(const int h, const int m, const int s){
    return h*3600+m*60+s;
}

void calculateDegree(const int second, vector<double>& degree){
    const int h = second / 3600;
    const int m = second % 3600 / 60;
    const int s = second % 60;
    
    const double secondDegree = 6.0 * s;
    const double minuteDegree = 6.0 * m + 0.1 * s;
    const double hourDegree = 30.0 * (h%12) + 0.5 * m + (1/120) * s;
    
    degree.push_back(hourDegree);
    degree.push_back(minuteDegree);
    degree.push_back(secondDegree);
}

bool isMatch(vector<double>& currentDegree, vector<double>& nextDegree, const int matchIndex){
    if(currentDegree[2] < currentDegree[matchIndex] && nextDegree[matchIndex] <= nextDegree[2])
        return true;
    
    if(currentDegree[2] == 354 && 354 < currentDegree[matchIndex])
        return true;
    
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    const int startSecond = calculateSecond(h1,m1,s1);
    const int endSecond = calculateSecond(h2,m2,s2);
    
    for(int second = startSecond; second<endSecond; ++second){
        vector<double> currentSecondDegree, nextSecondDegree;
        
        calculateDegree(second, currentSecondDegree);
        calculateDegree(second+1, nextSecondDegree);
        
        const bool isMinuteMatch = isMatch(currentSecondDegree, nextSecondDegree, 1);
        const bool isHourMatch = isMatch(currentSecondDegree, nextSecondDegree, 0);
        
        if(isMinuteMatch && isHourMatch){
            if(nextSecondDegree[0] == nextSecondDegree[1])
                ++answer;
            else
                answer+=2;
        }
        else if(isMinuteMatch || isHourMatch){
            ++answer;
        }
    }
    
    if(startSecond==0 || startSecond==12*3600)
        ++answer;
    
    return answer;
}
