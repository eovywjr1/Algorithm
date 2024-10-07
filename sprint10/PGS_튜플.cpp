#include <string>
#include <vector>
#include <set>
#include <array>

using namespace std;

vector<int> solution(string s)
{
    array<multiset<int>, 501> tupleSetBySize;
    string elementText = "";
    int tupleSetSize = 0;
    multiset<int> currentTupleSet;
    bool isRangeTupleSet = false;

    for (const char text : s)
    {
        switch (text)
        {
        case '{':
            isRangeTupleSet = true;
            tupleSetSize = 0;

            break;

            // 집합의 길이에 맞는 튜플 집합을 저장
        case '}':
            if (isRangeTupleSet == false)
                break;

            currentTupleSet.insert(stoi(elementText));

            ++tupleSetSize;
            tupleSetBySize[tupleSetSize] = currentTupleSet;

            currentTupleSet.clear();
            isRangeTupleSet = false;

            break;

        case ',':
            if (isRangeTupleSet)
            {
                ++tupleSetSize;
                currentTupleSet.insert(stoi(elementText));
            }

            elementText.clear();

            break;

        default:
            elementText += text;

            break;
        }
    }

    vector<int> answer;

    for (auto it = tupleSetBySize.begin() + 1; it != tupleSetBySize.end(); ++it)
    {
        // 최대 길이의 튜플 집합까지 모두 검사한 경우
        if (it->empty())
            break;

        for (const int tupleElement : answer)
        {
            it->erase(tupleElement);
        }

        answer.push_back(*(it->begin()));
    }

    return answer;
}
