class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast, slow, has_zero = false;
        for (slow = 0, fast = 0; fast < nums.size(); ++fast){
            if (nums[fast] != 0 && !has_zero){
                slow++;
                continue;
            }
            if (nums[fast] == 0 && !has_zero) {
                has_zero = true;
            }
            if (nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for (; slow < nums.size(); ++slow){
            nums[slow] = 0;
        }
    }
};