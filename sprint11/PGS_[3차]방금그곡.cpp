#include <bits/stdc++.h>

using namespace std;

struct MusicInfo{
    int playTime = 0;
    string title;
    string sheet;
};

void convertSharp(string& s){
    map<char, char> m;
    m.insert({'C', 'H'});
    m.insert({'D', 'I'});
    m.insert({'F', 'J'});
    m.insert({'G', 'K'});
    m.insert({'A', 'L'});
    
    for(int i=0; i<s.length(); i++) {
        if(s[i]=='#') {
            s[i-1]=m[s[i-1]];
            s.erase(s.begin()+i);
            
            i--;
        }
    }
}

int ctoi(const char text){
    return text - '0';
}

void getMusicInfo(const string& musicinfo, MusicInfo& outMusicInfo){
    const int startMinuteTime = (ctoi(musicinfo[0]) * 10 + ctoi(musicinfo[1])) * 60 + ctoi(musicinfo[3]) * 10 + ctoi(musicinfo[4]);
    const int endMinuteTime = (ctoi(musicinfo[6]) * 10 + ctoi(musicinfo[7])) * 60 + ctoi(musicinfo[9]) * 10 + ctoi(musicinfo[10]);
    
    outMusicInfo.playTime = endMinuteTime - startMinuteTime;
    
    int musicinfoStringIndex = 12;
    while(musicinfo[musicinfoStringIndex] != ',')
    {
        outMusicInfo.title += musicinfo[musicinfoStringIndex];
        ++musicinfoStringIndex;
    }
    
    outMusicInfo.sheet = musicinfo.substr(musicinfoStringIndex + 1);
    convertSharp(outMusicInfo.sheet);
}

bool checkMemorizedMusic(const MusicInfo& musicinfo, const string& m)
{
    const int sheetLength = musicinfo.sheet.length();
    string playSheet;
    for(int time = 0; time < musicinfo.playTime; ++time ){
        playSheet += musicinfo.sheet[time % sheetLength];
    }
        
    return playSheet.find(m) != string::npos;
}

string solution(string m, vector<string> musicinfos) {
    convertSharp(m);
    
    int maxPlayTime = -1;
    string resultTitle = "(None)";
    
    for(string& musicinfo : musicinfos){
        MusicInfo musicInfoStruct;
        getMusicInfo(musicinfo, musicInfoStruct);
        
        if(checkMemorizedMusic(musicInfoStruct, m) && musicInfoStruct.playTime > maxPlayTime){
            maxPlayTime = musicInfoStruct.playTime;
            resultTitle = musicInfoStruct.title;
        }
    }
    
    return resultTitle;
}
