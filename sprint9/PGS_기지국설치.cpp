#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    const int validRange = 2 * w + 1;
    int answer = 0;
    int startInvalidNumber = 1;
    
    for(const int station : stations){
        if(startInvalidNumber < station - w){
            answer += (station - w - startInvalidNumber) / validRange;
            if((station - w - startInvalidNumber) % validRange > 0)
                ++answer;
        }
        
        startInvalidNumber = station + w + 1;
    }
    
    if(startInvalidNumber <= n){
        answer += (n - startInvalidNumber + 1) / validRange;
        if((n - startInvalidNumber + 1) % validRange > 0)
            ++answer;
    }
    
    return answer;
}
