class Solution {
public:
    int trap(vector<int>& height) {
        if (!height.size())
            return 0;
        vector<int> left_right = vector<int>(height.size());
        vector<int> right_left = vector<int>(height.size());
        
        left_right[0] = height[0];
        right_left[height.size()-1] = height[height.size()-1];
        
        int ini, end;
        for (ini = 1, end = height.size() - 2; ini < height.size(); ++ini, --end){
            left_right[ini] = max(height[ini], left_right[ini-1]);
            right_left[end] = max(height[end], right_left[end+1]);
        }
        int trapped = 0;
        for (int i = 0 ; i < height.size(); ++i){
            int smallest = min(left_right[i], right_left[i]);
            if (smallest){
                trapped += smallest - height[i];
                
            }
        }
        return trapped;
    }
};
