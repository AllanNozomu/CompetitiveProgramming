class Solution {
public:
    void print(vector<int>& nums){
        for (auto i : nums){
            cout << i;
        }
        cout << endl;
    }
    
    void sortColors(vector<int>& nums) {
        int zero_index = 0;
        int two_index = nums.size() - 1;
        
        for (int i = 0; i <= two_index; ++i){
            if (nums[i] == 0){
                nums[i] = nums[zero_index];
                nums[zero_index] = 0;
                zero_index ++;
            } else if (nums[i] == 2){
                nums[i] = nums[two_index];
                nums[two_index] = 2;
                two_index--;
                i--;
            }
        }
    }
};