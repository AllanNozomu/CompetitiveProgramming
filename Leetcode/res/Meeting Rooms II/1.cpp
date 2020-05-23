\*
Author: allannozomu
Runtime: 20 ms
Memory: 13.1 MB*\

class Solution {
private:
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> time_intervals;
        
        for (auto v : intervals){
            time_intervals.push_back({v[0], 1});
            time_intervals.push_back({v[1], 0});
        }
        sort(time_intervals.begin(), time_intervals.end());
        
        int curr_room = 0;
        int res = 0;
        
        for (auto time_interval : time_intervals){
            if (time_interval.second == 0){
                curr_room--;
            } else {
                curr_room++;
                res = max(res, curr_room);
            }
        }
        return res;
    }
};