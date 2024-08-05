#include <string>
#include <vector>
#include <limits.h>
#include <cmath>
#include <iostream>

using namespace std;

string solution(string s) {
    const size_t length = s.length();
    int minNumber = INT_MAX-1, maxNumber=(INT_MAX-1) * -1, number=0;
    bool isMinus=false;
    
    for(int index=0;index<length;++index)
    {
        if(s[index] == ' '){
            if(isMinus)
                number *= -1;
            
            minNumber = min(minNumber, number);
            maxNumber = max(maxNumber, number);
            
            number=0;
            isMinus=false;
            continue;
        }
        
        if(s[index] == '-'){
            isMinus = true;
            ++index;
        }
        
        number = number * 10 + s[index] - '0';
    }
    
    if(isMinus)
        number *= -1;
            
    minNumber = min(minNumber, number);
    maxNumber = max(maxNumber, number);
    
    
    return to_string(minNumber) + ' ' + to_string(maxNumber);
}
