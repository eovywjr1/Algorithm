#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<tuple<string, int, int>> fileHeaderNumberIndexTupleVector;
    
    for(int fileIndex = 0; fileIndex< files.size(); ++fileIndex){
        string head;
        string number;
        
        for(int fileStringIndex = 0; fileStringIndex < files[fileIndex].length(); ++fileStringIndex){
            if(files[fileIndex][fileStringIndex] >= '0' && files[fileIndex][fileStringIndex] <= '9')
                number += files[fileIndex][fileStringIndex];
            else if(number.empty())
                head += tolower(files[fileIndex][fileStringIndex]);
            else
                break;
        }
        
        fileHeaderNumberIndexTupleVector.push_back({head, stoi(number), fileIndex});
    }
    
    sort(fileHeaderNumberIndexTupleVector.begin(), fileHeaderNumberIndexTupleVector.end(), [](tuple<string, int, int>& a, tuple<string, int, int>& b){
        if(get<0>(a) != get<0>(b))
            return get<0>(a) < get<0>(b);
        
        if(get<1>(a) != get<1>(b))
            return get<1>(a) < get<1>(b);
        
        return get<2>(a) < get<2>(b);
    });
    
    vector<string> answer;
    
    for(const tuple<string, int, int>& sortedFile : fileHeaderNumberIndexTupleVector){
        answer.emplace_back(files[get<2>(sortedFile)]);
    }
    
    return answer;
}
