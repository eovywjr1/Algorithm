#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DeliveryOrPickup(int remainCap, vector<int>& deliveryOrPickupVector, int& deliveryOrPickupindex){
    int index = deliveryOrPickupindex;
    
    for(; index>=0; --index){
        if(deliveryOrPickupVector[index] <= 0)
            continue;
        
        const int tempRemainCap = remainCap;
        remainCap -= deliveryOrPickupVector[index];
        deliveryOrPickupVector[index] -= tempRemainCap;
        
        if(remainCap <= 0)
            break;
    }
    
    deliveryOrPickupindex = index;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int lastDeliveryIndex = n-1;
    int lastPickupIndex = lastDeliveryIndex;
    
    while(lastDeliveryIndex >= 0 || lastPickupIndex >= 0){
        while(lastDeliveryIndex >= 0 && deliveries[lastDeliveryIndex] <= 0)
            --lastDeliveryIndex;
        
        while(lastPickupIndex >= 0 && pickups[lastPickupIndex] <= 0)
            --lastPickupIndex;
        
        answer += (max(lastDeliveryIndex, lastPickupIndex) + 1) * 2;
        
        DeliveryOrPickup(cap, deliveries, lastDeliveryIndex);
        DeliveryOrPickup(cap, pickups, lastPickupIndex);
    }
    
    return answer;
}
