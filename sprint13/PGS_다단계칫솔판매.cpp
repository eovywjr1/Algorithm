#include <bits/stdc++.h>

using namespace std;

const int Cost = 100;

struct MemberInfo
{
public:
    string Reference;
    long long Profits = 0;
};

map<string, MemberInfo> Members;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    const int enrollSize = enroll.size();
    for(int Index = 0; Index < enrollSize; ++Index)
    {
        MemberInfo Info;
        Info.Reference = referral[Index];
        Members[enroll[Index]] = Info;
    }

    const int SellCount = seller.size();
    
    for(int Index = 0; Index < SellCount; ++Index)
    {
        string Reference = seller[Index];
        int Profits = amount[Index] * Cost;
        
        while(Profits > 0 && Reference != "-")
        {
            MemberInfo& SellerInfo = Members[Reference];
            int Distribution = Profits * 0.1f;
            SellerInfo.Profits += ( Distribution > 0 ) ? Profits - Distribution : Profits;
            
            Profits *= 0.1f;
            Reference = SellerInfo.Reference;
        }
    }
    
    vector<int> answer;
    
    for(const string& Enroll : enroll)
    {
        answer.push_back(Members[Enroll].Profits);
    }
    
    return answer;
}
