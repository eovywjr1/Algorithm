int solution(int n) {
    int answer = 1; // n 자기 자신 카운트
    
    for(int startNum = 1; startNum < n; ++startNum ){
        int sum = startNum;
        
        for(int addNum = startNum + 1; addNum < n; ++addNum){
            sum += addNum;
            
            if(n <= sum)
                break;
        }
        
        if(n == sum)
            ++answer;
    }
    
    return answer;
}
