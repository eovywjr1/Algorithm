#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    const int friendsSize = friends.size();
    vector<vector<int>> giftPerFriendSumVector(friendsSize, vector<int>(friendsSize,0));
    vector<int> giftPointVector(friendsSize);
    map<string, int> friendIndexMap;
    
    for( int index = 0; index < friendsSize; ++index){
        friendIndexMap[friends[index]] = index;
    }
    
     for(const string gift : gifts){
        const int spaceIndex = gift.find(' ', 0);
        const int giveFriendIndex = friendIndexMap[gift.substr(0, spaceIndex)];
        const int receivedFriendIndex = friendIndexMap[gift.substr(spaceIndex + 1)];
        
        ++giftPerFriendSumVector[giveFriendIndex][receivedFriendIndex];
        --giftPerFriendSumVector[receivedFriendIndex][giveFriendIndex];
         
        ++giftPointVector[giveFriendIndex];
        --giftPointVector[receivedFriendIndex];
    }
    
    for(int i=0; i<friendsSize; ++i)
    {
        int giftCount = 0;
        
        for(int j=0; j<friendsSize; ++j)
        {
            if(i==j)
                continue;
            
            if(giftPerFriendSumVector[i][j]<0)
                continue;
            
            if(giftPerFriendSumVector[i][j]>0)
                ++giftCount;
            else if(giftPointVector[i]>giftPointVector[j])
                ++giftCount;
        }
        
        answer = (giftCount > answer) ? giftCount : answer;
    }
    
    return answer;
}
