#include <string>
#include <vector>
#include <stack>

using namespace std;

const int InvalidIndex = -1;

struct TableStruct
{
    int PrevIndex = InvalidIndex, NextIndex = InvalidIndex;
};

vector<TableStruct> TableStructs;
stack<int> DeleteIndexStack;

void DeleteRow(int& CurrentIndex)
{
    DeleteIndexStack.push(CurrentIndex);
    
    if(TableStructs[CurrentIndex].PrevIndex != InvalidIndex)
    {
        TableStructs[TableStructs[CurrentIndex].PrevIndex].NextIndex = TableStructs[CurrentIndex].NextIndex;
    }

    if(TableStructs[CurrentIndex].NextIndex != InvalidIndex)
    {
        TableStructs[TableStructs[CurrentIndex].NextIndex].PrevIndex = TableStructs[CurrentIndex].PrevIndex;
    }
    
    if(TableStructs[CurrentIndex].NextIndex != InvalidIndex)
    {
        CurrentIndex = TableStructs[CurrentIndex].NextIndex;
    }
    else
    {
        CurrentIndex = TableStructs[CurrentIndex].PrevIndex;
    }
}

void RevertRecentDelete()
{
    const int RevertIndex = DeleteIndexStack.top();
    DeleteIndexStack.pop();
    
    if(TableStructs[RevertIndex].PrevIndex != InvalidIndex)
    {
        TableStructs[TableStructs[RevertIndex].PrevIndex].NextIndex = RevertIndex;
    }

    if(TableStructs[RevertIndex].NextIndex != InvalidIndex)
    {
        TableStructs[TableStructs[RevertIndex].NextIndex].PrevIndex = RevertIndex;
    }
}

string solution(int n, int k, vector<string> cmd) {
    TableStructs.resize(n);
    for(int Index = 0; Index < n; ++Index)
    {
        TableStructs[Index].PrevIndex = Index - 1;
        TableStructs[Index].NextIndex = Index + 1;
    }
    
    TableStructs[n - 1].NextIndex = -1;
    
    int CurrentIndex = k;
    for(const string& CmdString : cmd)
    {
        const char CmdType = CmdString[0];   
        
        switch (CmdType)
        {
            case 'U':
                {
                    int MoveAmount = stoi(CmdString.substr(2));
                    while(MoveAmount > 0)
                    {
                        CurrentIndex = TableStructs[CurrentIndex].PrevIndex;
                        --MoveAmount;
                    }
                    
                    break;
                }
            case 'D':
                {
                    int MoveAmount = stoi(CmdString.substr(2));
                    
                    while(MoveAmount > 0)
                    {
                        CurrentIndex = TableStructs[CurrentIndex].NextIndex;
                        --MoveAmount;
                    }
                    
                    break;
                }
            case 'C':
                {
                    DeleteRow(CurrentIndex);
                    break;
                }
            case 'Z':
                {
                    RevertRecentDelete();
                    break;
                }
        }
    }
    
    string ValidRows(n, 'O');
    
    while(!DeleteIndexStack.empty())
    {
        ValidRows[DeleteIndexStack.top()] = 'X';
        DeleteIndexStack.pop();
    }
    
    return ValidRows;
}
