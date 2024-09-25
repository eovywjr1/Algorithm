using namespace std;

// 2진수로 변환했을 때 1의 개수 반환 함수
int getOneCount(int nun){
    int oneCount = 0;
        
    while(nun > 0){
        if(nun % 2 == 1)
            ++oneCount;
            
        nun /= 2;
    }
    
    return oneCount;
}

int solution(int n) {
    const int nOneCount = getOneCount(n);
    
    for(int num = n+1;n<=1000000;++num){
        if(nOneCount == getOneCount(num))
            return num;
    }
    
    return 0;
}
