\*
Author: allannozomu
Runtime: 16 ms
Memory: 11.5 MB*\

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0){
            return 0;
        }
        
        sort(intervals.begin(), intervals.end());
        
        auto curr_interval = intervals[0];
        int answer = 0;
        
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i,0] < curr_interval[1]){
                answer++;
                if (curr_interval[1] > intervals[i,1]) {
                    curr_interval = intervals[i];
                }
            } else {
                curr_interval = intervals[i];
            }
        }
        return answer;
    }
};