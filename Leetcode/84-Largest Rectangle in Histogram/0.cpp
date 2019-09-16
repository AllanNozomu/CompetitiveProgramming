class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 0) return 0;
        
        stack<pair<int, int>> ss;
        int max_area = 0;
        
        for (int i = 0; i < heights.size(); i++){
            int height = heights[i];
            while (!ss.empty() && height <= ss.top().first){
                pair<int, int> top = ss.top();
                ss.pop();
                int area = top.first * (ss.empty() ? i : i - ss.top().second - 1);
                max_area = max(max_area, area);
            }
            ss.push({height, i});
        }
        while (!ss.empty()){
            pair<int, int> top = ss.top();
            ss.pop();
            int area = top.first * (ss.empty() ? heights.size() : heights.size() - ss.top().second - 1);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
    