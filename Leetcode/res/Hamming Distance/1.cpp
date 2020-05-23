\*
Author: allannozomu
Runtime: 0 ms
Memory: 8.1 MB*\

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0 ; i < 31; ++i){
            if ((x & (1 << i)) != (y & (1 << i))){
                res++;
            }
        }
        return res;
    }
};