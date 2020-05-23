\*
Author: allannozomu
Runtime: 20 ms
Memory: 9.8 MB*\

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        
        while(left < right){
            int min_height = min(height[left], height[right]);
            max_area = max(max_area, (right - left) * min_height);
            
            if (height[left] == min_height) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};