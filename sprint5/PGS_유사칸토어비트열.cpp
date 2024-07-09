#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int check(long long size, const long long l, const long long r){
    if(r < l)
        return 0;
    
    if(size==1)
        return 1;
    
    int count = 0;
    const long long prevSize = size / 5;
    for(int index = 0; index<5; ++index){
        if(index==2)
            continue;
        
        count += check(prevSize, max(prevSize*index, l) - (prevSize*index), min(prevSize*(index+1)-1, r) - (prevSize*index));
    }
    
    return count;
}

int solution(int n, long long l, long long r) {
    return check(pow(5,n), l-1, r-1);
}
