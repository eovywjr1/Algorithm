#include <bits/stdc++.h>

using namespace std;

int getMaxSumByNotAdjacent(const vector<int>& sticker, bool isFirstSticker){
    const int stickerSize = sticker.size();
    const int findLastIndex = isFirstSticker ? stickerSize - 2 : stickerSize - 1;
    
    int dpPrev = isFirstSticker ? sticker[0] : sticker[1];
    int dpPrevPrev = isFirstSticker ? sticker[0] : 0;
    
    for(int stickerIndex = 2; stickerIndex <= findLastIndex; ++stickerIndex){
        const int tempAnswer = max(dpPrev, dpPrevPrev + sticker[stickerIndex]);
        
        dpPrevPrev = dpPrev;
        dpPrev = tempAnswer;
    }
    
    return dpPrev;
}

int solution(vector<int> sticker)
{
    const int stickerSize = sticker.size();
    if(stickerSize == 1)
        return sticker[0];
    
    return max(getMaxSumByNotAdjacent(sticker, true), getMaxSumByNotAdjacent(sticker, false));
}
