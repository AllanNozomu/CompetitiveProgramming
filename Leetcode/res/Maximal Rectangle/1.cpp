\*
Author: allannozomu
Runtime: 28 ms
Memory: 10.4 MB*\

class Solution {
public:
    int maxRectangle(vector<int>& v){
        int max_area = 0;

        for (int slow = 0 ; slow < v.size(); ++slow){
            int min_height = v[slow];
            for (int fast = slow; fast < v.size() && v[fast]; ++fast) {
                min_height = min(min_height, v[fast]);
                max_area = max(max_area, (fast - slow + 1) * min_height);
            }
        }
        return max_area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        
        vector<int> heights (matrix[0].size());
        int max_area = 0;
        
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (matrix[i,j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            max_area = max(max_area, maxRectangle(heights));
        }
        return max_area;
    }
};