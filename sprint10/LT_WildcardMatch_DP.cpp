class Solution {
public:
    bool isMatch(string s, string p) {
        const int sLength = s.length();
        const int pLength = p.length();
        vector<vector<bool>> matchDp(pLength + 1, vector<bool>(sLength + 1, false));
        
        matchDp[0][0] = true;

        // 빈 문자열에 처음 * 패턴이 연속적으로 매칭되는 케이스 초기화
        for(int pIndex = 1; pIndex <= pLength && p[pIndex-1] == '*'; ++pIndex ){
                matchDp[pIndex][0] = matchDp[pIndex-1][0];
        }


        for(int pIndex = 1; pIndex <= pLength; ++pIndex ){
            for(int sIndex = 1; sIndex <= sLength; ++sIndex){
                if(p[pIndex-1] == '*'){
                    // 현재 *를 무시하거나 추가
                    matchDp[pIndex][sIndex] = matchDp[pIndex][sIndex-1] || matchDp[pIndex-1][sIndex];
                }
                else if(p[pIndex-1] == s[sIndex-1] || p[pIndex-1] == '?'){
                    matchDp[pIndex][sIndex] =  matchDp[pIndex-1][sIndex-1];
                }
            }
        }

        return matchDp[pLength][sLength];
    }
};
