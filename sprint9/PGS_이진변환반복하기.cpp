#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    int convertCount = 0;
    int zeroRemoveCount = 0;
    
    while(s != "1"){
        ++convertCount;
        
        string tempString;
        
        for(const char text : s){
            if(text == '1')
                tempString += '1';
            else
                ++zeroRemoveCount;
        }
        
        int tempStringLength = tempString.length();
        s.clear();
        
        while(tempStringLength > 0){
            s.insert(0, to_string(tempStringLength % 2));
            tempStringLength /= 2;
        }
    }
    
    return {convertCount, zeroRemoveCount};
}
