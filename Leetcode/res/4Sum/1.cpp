\*
Author: allannozomu
Runtime: 68 ms
Memory: 13.1 MB*\

class Solution {
public:
    string make_key(int a, int b, int c, int d){
        return to_string(a) + ";" + to_string(b) + ";" + to_string(c) + ";" + to_string(d);
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        unordered_set<string> visited;
        
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                int l = j + 1;
                int r = nums.size() - 1;
                while(l < r) {
                    int num_i = nums[i], num_j = nums[j], num_l = nums[l], num_r = nums[r];
                    int sum = num_i + num_j + num_l + num_r;
                    
                    if (sum == target) {
                        string key = make_key(num_i,num_j,num_l,num_r);
                        if (visited.find(key) == visited.end()){
                            visited.insert(key);
                            result.push_back(vector<int>({num_i,num_j,num_l,num_r}));
                        }
                        r--;
                        l++;
                    } else if (sum > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        return result;
    }
    
};