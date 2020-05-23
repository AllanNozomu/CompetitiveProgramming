\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.3 MB*\

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int jewel_map[256] = {};
        int jewel_count = 0;
        
        for (char j : J){
            jewel_map[j] = 1;
        }
        for (char s : S){
            if (jewel_map[s]){
                jewel_count++;
            }
        }
        return jewel_count;
    }
};