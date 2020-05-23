\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.5 MB*\

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> stones_set;
        
        for (int stone : stones){
            stones_set.insert(stone);
        }
        
        while(stones_set.size() > 1){
            int stone1 = *(stones_set.rbegin());
            stones_set.erase(stones_set.find(stone1));
            
            int stone2 = *(stones_set.rbegin());
            stones_set.erase(stones_set.find(stone2));
            
            if (stone1 - stone2 > 0)
                stones_set.insert(stone1 - stone2);
        }
        
        if (stones_set.empty()) return 0;
        return *(stones_set.begin());
    }
};