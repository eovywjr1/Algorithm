#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMinute(const string time){
    const int hour = time[0] * 10 + time[1];
    const int minute = time[3] * 10 + time[4];
    
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<int> remainBookTimeVector;
    
    sort(book_time.begin(), book_time.end());
    
    for(const vector<string>& bookTime : book_time){
        const int currentTime = getMinute(bookTime[0]);
        const int endBookTime = getMinute(bookTime[1]) + 10;
        bool isFindEmptyRoom = false;
        
        for(int& remainBookTime : remainBookTimeVector){
            if(remainBookTime <= currentTime){
                remainBookTime = endBookTime;
                isFindEmptyRoom = true;
                break;
            }
        }
        
        if(isFindEmptyRoom==false){
            remainBookTimeVector.push_back(endBookTime);
        }
    }
         
    return remainBookTimeVector.size();
}
