#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string,int> playerRankMap;
    
    for(int index=0;index<players.size();++index){
        playerRankMap[players[index]] = index+1;
    }
    
    for(string calling : callings){
        const int callingRankIndex = playerRankMap[calling]-1;
        
        --playerRankMap[calling];
        ++playerRankMap[players[callingRankIndex-1]];
        
        swap(players[callingRankIndex], players[callingRankIndex-1]);
    }
    
    return players;
}
