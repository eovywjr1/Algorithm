#include <bits/stdc++.h>

using namespace std;

void NumberToBit(string& Bit, long long Number)
{
    while(Number>0)
    {
        Bit = to_string(Number%2) + Bit;
        Number /= 2;
    }
}

void FillBit(string& Bit)
{
    int NodeCount = 1;
    
    while(Bit.length() > NodeCount - 1)
    {
        NodeCount *= 2;    
    }
    
    const int FillCount = NodeCount - 1 - Bit.length();
    for(int i=0;i<FillCount;++i)
    {
        Bit = "0" + Bit;
    }
}

bool IsBinaryTree(const string& Bit, const int Start, const int End)
{
    if(Start == End)
    {
        return true;
    }
    
    const int Root = (Start + End) / 2;
    const int LeftRoot = (Start + Root - 1) / 2;
    const int RightRoot = (Root + 1 + End) / 2;
    if(Bit[Root] == '0' && (Bit[LeftRoot] == '1' || Bit[RightRoot] == '1'))
    {
        return false;    
    }
    
    return IsBinaryTree(Bit, Start, Root - 1) && IsBinaryTree(Bit, Root + 1, End);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(const long long Number : numbers)
    {
        string Bit;
        NumberToBit(Bit, Number);
        FillBit(Bit);
        
        const bool bBinaryTree = IsBinaryTree(Bit, 0, Bit.length() - 1);
        answer.push_back(static_cast<int>(bBinaryTree));
    }
    
    return answer;
}
