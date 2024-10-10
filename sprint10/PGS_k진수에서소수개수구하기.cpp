#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrimeNumber(unsigned long number){
    if(number == 1)
        return false;
    
    for(long long divideNumber = 2; divideNumber <= sqrt(number); ++divideNumber){
        if(number % divideNumber == 0)
            return false;
    }
    
    return true;
}

string getConvertNumberText(int number, const int jinsu){
    string convertNumberText = "";
    
    while(number > 0){
        convertNumberText.insert(0, to_string(number % jinsu));
        number /= jinsu;
    }
    
    return convertNumberText;
}

int solution(int n, int k) {
    const string convertNumberText = getConvertNumberText(n,k);
    
    if(convertNumberText.length() == 1 && convertNumberText != "0")
        return 1;
    
    int answer = 0;
    string tempNumberText = "";
    
    for(const char numberText : convertNumberText){
        if(numberText=='0'){
            if(tempNumberText.empty() == false && isPrimeNumber(stoul(tempNumberText)))
                ++answer;
                
            tempNumberText.clear();
        }
        else{
            tempNumberText += numberText;
        }
    }
    
    if(tempNumberText.empty() == false && isPrimeNumber(stoul(tempNumberText)))
        ++answer;
    
    return answer;
}
