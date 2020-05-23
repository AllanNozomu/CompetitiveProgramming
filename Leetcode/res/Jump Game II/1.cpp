\*
Author: allannozomu
Runtime: 12 ms
Memory: 11.1 MB*\

class Solution {
public:
    int jump(vector<int>& nums) {
        int end = nums.size() - 1;
        vector<int> visited(nums.size(), 0);
        
        
        queue<pair<int, int>> positions;
        visited[0] = 1;
        pair<int, int> max_layer = {0,0};
        positions.push({0,0});
        
        while(!positions.empty()){
            pair<int, int> curr_position = positions.front();
            positions.pop();
            
            if (curr_position.first == end) return curr_position.second;
            
            for (int i = min(nums[curr_position.first], end - curr_position.first); i >= 1 && !visited[curr_position.first + i]; --i){
                visited[curr_position.first + i] = 1;
                positions.push({curr_position.first + i, curr_position.second + 1 });
            }
        }
        return -1;
    }
};