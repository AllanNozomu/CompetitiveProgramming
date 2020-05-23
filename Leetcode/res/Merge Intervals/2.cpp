\*
Author: allannozomu
Runtime: 24 ms
Memory: 13.6 MB*\

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> all_events;
        
        for (auto interval : intervals){
            all_events.push_back({interval[0], 0});
            all_events.push_back({interval[1], 1});
        }
        
        sort(all_events.begin(), all_events.end());
        
        int open_count = 0;
        int open_time = 0;
        vector<vector<int>> merged_intervals;
        
        for (auto event : all_events){
            if (event.second == 0){
                if (open_count == 0){
                    open_time = event.first;
                } 
                open_count++;
            } else {
                open_count--;
                if (open_count == 0){
                    merged_intervals.push_back({open_time, event.first});
                }
            }
        }
        return merged_intervals;
    }
};