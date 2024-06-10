#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int tempHealth = health;
    int time = 0;
    const int durationTime = bandage[0];
    const int curePerTime = bandage[1];
    const int additionalCure = bandage[2];
    
    for(vector<int> attack : attacks){
        const int damageTime = attack[0];
        const int damage = attack[1];
        const int unDamagedTime = damageTime - time - 1;
        
        tempHealth += unDamagedTime / durationTime * additionalCure;
        tempHealth += unDamagedTime * curePerTime;
        
        tempHealth = (tempHealth > health) ? health : tempHealth;
        
        tempHealth -= damage;
        
        if(tempHealth <= 0)
            return -1;
        
        time = damageTime;
    }
    
    return tempHealth;
}
