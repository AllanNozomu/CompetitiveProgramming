class Solution {
public:
    int numWays(int n, int k, int last, int can_repeat, vector<vector<vector<int>>>& memo){
        if (n == 1 && can_repeat) {
            return k;
        }
        if (n == 0) {
            return 1;
        }

        if (last >= 0 && memo[n][last][can_repeat]) return memo[n][last][can_repeat];
        
        int count = 0;
        for (int i = 0 ; i < k; ++i){
            if (i == last){
                if (can_repeat)
                    count += numWays(n - 1, k, last, 0, memo);
            } else {
                count += numWays(n - 1, k, i, 1, memo);
            }
        }
        if (last >= 0) memo[n][last][can_repeat] = count;
        return count;
    }
    
    int numWays(int n, int k) {
        if (k == 0 || n == 0) return 0;
        
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>> (k, vector<int>(2) ) );
        
        return numWays(n, k, -1, 0, memo);
    }
};