#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

void getBanCase(const int userCount, const int banCount, const vector<vector<int>>& possibleBanIndexes, vector<int> remainBans, const int currentUserIndex, set<set<int>>& banCases, vector<int> banUserIndexes){
    if(remainBans.empty()){
        set<int> banCase;
        
        for(const int banUserIndex : banUserIndexes){
            banCase.insert(banUserIndex);
        }
        
        banCases.insert(banCase);
        
        return;
    }
    
    if( userCount <= currentUserIndex){
        return;
    }
    
    for(int userIndex = currentUserIndex; userIndex < userCount; ++userIndex){
        for(const int possibleBanIndex : possibleBanIndexes[userIndex]){
            auto it = find(remainBans.begin(), remainBans.end(), possibleBanIndex);
            const int removeBanIndex = *it;
            
            if(it == remainBans.end()){
                continue;
            }
            
            banUserIndexes.push_back(userIndex);
            remainBans.erase(it);
            
            getBanCase(userCount, banCount, possibleBanIndexes, remainBans, userIndex + 1, banCases, banUserIndexes);
            remainBans.push_back(removeBanIndex);
            banUserIndexes.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    const int userCount = user_id.size();
    const int banCount = banned_id.size();
    vector<vector<int>> possibleBanIndexVector(userCount);
    
    for(int userIndex = 0; userIndex < userCount; ++userIndex){
        for(int bannedIdIndex = 0; bannedIdIndex < banCount; ++bannedIdIndex){
            bool isBanned = true;
            
            if(user_id[userIndex].length() != banned_id[bannedIdIndex].length()){
                continue;
            }
            
            for(int stringIndex = 0; stringIndex < user_id[userIndex].length(); ++stringIndex){
                if(banned_id[bannedIdIndex][stringIndex] == '*'){
                    continue;
                }
                
                if(banned_id[bannedIdIndex][stringIndex] != user_id[userIndex][stringIndex]){
                    isBanned = false;
                    break;
                }
            }
            
            if(isBanned){
                possibleBanIndexVector[userIndex].push_back(bannedIdIndex);
            }
        }
    }
    
    vector<int> remainBans(banCount,0);
    for(int banIndex = 0; banIndex < banCount; ++banIndex){
        remainBans[banIndex] = banIndex;
    }
    
    set<set<int>> banCases;
    getBanCase(userCount, banCount, possibleBanIndexVector, remainBans, 0, banCases, vector<int>());
    
    return banCases.size();
}
