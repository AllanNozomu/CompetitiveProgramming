\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.3 MB*\

class Solution {
public:
    
    int climbStairs(int n) {
        vector<int> ways;
        ways.push_back(1);
        ways.push_back(2);
        for (int i = 2; i < n; ++i){
            ways.push_back(ways[i-2] + ways[i-1]);
        }
        return ways[n - 1];
    }
};