class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        vector<int> res = vector<int>(2);
        
        for (int i = 0; i < nums.size(); ++i){
            int num = nums[i];
            
            if (memo.find(target - num) != memo.end()){
                res[0] = i;
                res[1] = memo[target-num];
                return res;
            } 
            memo[num] = i;
        }

        return res;
    }
};