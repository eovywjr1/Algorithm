#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 숫자를 n진법으로 변환한 string을 반환
void convert(string& s, int number, const int n){
    while(number > 0){
        const int remainNumber = number % n;
        s += (remainNumber >= 10) ? 'A' + remainNumber - 10 : '0' + remainNumber;
        number /= n;
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string currentNumberString = "0";
    int tellCount = 0;
    int order = 0;
    int currentTextIndex = 0;
    int currentNumber = 0;
    
    while(tellCount < t){
        // 튜브 차례
        if(order + 1 == p){
            answer += currentNumberString[currentTextIndex];
            ++tellCount;
        }
        
        --currentTextIndex;
        // 해당 숫자를 모두 말했을 때
        if(currentTextIndex < 0){
            ++currentNumber;
            currentNumberString="";
            
            convert(currentNumberString, currentNumber, n);
            currentTextIndex = currentNumberString.length() - 1;
        }
        
        order = (order + 1) % m;
    }
    
    return answer;
}
