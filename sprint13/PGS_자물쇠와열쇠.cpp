#include <vector>

using namespace std;

vector<vector<int>> Map;
int KeySize = 0;
int LockSize = 0;
int MapSize = 0;
int StartLockIndex = 0;
int EndLockIndex = 0;

void InitializeMap(const vector<vector<int>>& Lock)
{
    Map.resize(MapSize);
    
    for(int i=0;i<MapSize;++i)
    {
        Map[i].resize(MapSize);
    }
    
    StartLockIndex = KeySize - 1;
    EndLockIndex = MapSize - KeySize;
    
    for(int i= 0; i<LockSize;++i)
    {
        for(int j=0;j<LockSize;++j)
        {
            Map[StartLockIndex + i][StartLockIndex + j] = Lock[i][j];
        }
    }
}

void RotateKey(vector<vector<int>>& Key)
{
    vector<vector<int>> TempKey(KeySize, vector<int>(KeySize));
    
    for(int i=0;i<KeySize;++i)
    {
        for(int j=0;j<KeySize; ++j)
        {
            TempKey[i][j] = Key[KeySize-j-1][i];
        }
    }
    
    Key = TempKey;
}

bool Answer = false;

bool IsUnlock(vector<vector<int>>& Key, const int StartI, const int StartJ)
{
    vector<vector<int>> TempMap = Map;
        
    for(int i=0;i<KeySize;++i)
    {
        for(int j=0;j<KeySize;++j)
        {
            const int MapI = StartI + i;
            const int MapJ = StartJ + j;
            
            if(StartLockIndex <= MapI && MapI <= EndLockIndex && StartLockIndex <= MapJ && MapJ <= EndLockIndex)
            {
                if(Key[i][j] == TempMap[MapI][MapJ])
                {
                    return false;
                }
                
                TempMap[MapI][MapJ] = 1;
            }
        }
    }
    
    for(int i=StartLockIndex; i <= EndLockIndex; ++i)
    {
        for(int j=StartLockIndex; j <= EndLockIndex; ++j)
        {
            if(TempMap[i][j] == 0)
            {
                return false;
            }
        }
    }
    
    return true;
}

void FindKeyTransform(vector<vector<int>>& Key)
{
    for(int k=0;k<4;++k)
    {
        for(int i=0;i<=EndLockIndex;++i)
        {
            for(int j=0;j<=EndLockIndex;++j)
            {
                if(IsUnlock(Key, i, j))
                {
                    Answer = true;
                    return;
                }
            }
        }
        
        RotateKey(Key);
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    KeySize = key.size();
    LockSize = lock.size();
    MapSize = LockSize + 2 * (KeySize - 1);
    
    InitializeMap(lock);
    FindKeyTransform(key);
    
    return Answer;
}
