#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void toLower(string& s){
    for(char& text : s){
        if(text >= 'A' && text <= 'Z')
            text = text - 'A' + 'a';
    }
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0)
        return cities.size() * 5;
    
    vector<string> cache;
    int answer = 0;
    
    const int citiesSize = cities.size();
    for(int index = 0; index<citiesSize; ++index){
        toLower(cities[index]);
        
        // cache hit
        const auto cityIterator = find(cache.begin(), cache.end(), cities[index]);
        if(cityIterator != cache.end()){
            cache.erase(cityIterator);
            cache.push_back(cities[index]);
            ++answer;
            
            continue;
        }
        
        // chche miss
        if(cache.size() < cacheSize){
            cache.push_back(cities[index]);
        }
        else{
            cache.erase(cache.begin());
            cache.push_back(cities[index]);
        }
            
        answer += 5;
    }
    
    return answer;
}
