#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long check(const int r1, const int r2){
    long long count = 0;
    
    for(int x=1; x<=r2;++x){
        const double tempY1 = sqrt(pow(r1, 2) - pow(x, 2));
        int y1 = static_cast<int>(tempY1);
        const int y2 = static_cast<int>(sqrt(pow(r2, 2) - pow(x, 2)));
        
        if( y1 < tempY1 )
            ++y1;
        
        if(r1 < x)
            y1 = 0;
        
        count += y2-y1+1;
    }
    
    return count;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    
    answer = check(r1, r2) * 4;
    
    return answer;
}
