class Solution {
public:
    bool isMatch(string s, string p) {
        const int sLength = s.length();
        const int pLength = p.length();
        int sIndex = 0;
        int pIndex = 0;
        int starPIndex = -1;
        int starSIndex = -1;

        while(sIndex < sLength){
            if(s[sIndex] == p[pIndex] || p[pIndex] == '?'){
                ++sIndex;
                ++pIndex;
                
                continue;
            }
            
            if(p[pIndex]=='*'){
                starPIndex = pIndex;
                ++pIndex;
                starSIndex = sIndex;

                continue;
            }

            if(starPIndex != -1){
                pIndex = starPIndex + 1;
                ++starSIndex;
                sIndex = starSIndex;

                continue;
            }

            return false;
        }

        while(pIndex < pLength){
            if(p[pIndex] != '*'){
                return false;
            }

            ++pIndex;
        }

        return true;
    }
};
