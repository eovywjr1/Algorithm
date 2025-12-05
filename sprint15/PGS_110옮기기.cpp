#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> s)
{
    vector<string> answer;

    for (string& Str : s)
    {
        int Count = 0;

        for (int i = (int)Str.length() - 2; i >= 0; --i)
        {
            if (Str.substr(i, 3) == "110")
            {
                ++Count;
                Str.erase(i, 3);
            }
        }

        int LastZeroIndex = Str.length() - 1;
        for (; LastZeroIndex >= 0; --LastZeroIndex)
        {
            if (Str[LastZeroIndex] == '0')
            {
                break;
            }
        }

        string InsertStr;
        for (int i = 0; i < Count; ++i)
        {
            InsertStr += "110";
        }

        if (LastZeroIndex >= 0)
        {
            Str.insert(LastZeroIndex + 1, InsertStr);
        }
        else
        {
            Str.insert(0, InsertStr);
        }

        answer.push_back(Str);
    }

    return answer;
}
