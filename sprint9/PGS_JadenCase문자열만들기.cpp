#include <string>

using namespace std;

string solution(string s) {
    bool isFirstText = true;
    
    for(char& text : s){
        if(text == ' '){
            isFirstText = true;
            continue;
        }
        
        if(isFirstText && (text >= 'a' && text <= 'z'))
            text = text - 'a' + 'A';
        else if(isFirstText == false && (text >= 'A' && text <= 'Z'))
            text = text - 'A' + 'a';
            
        isFirstText = false;    
    }
    
    return s;
}
