\*
Author: allannozomu
Runtime: 24 ms
Memory: 14.1 MB*\

class Solution {
private:
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        multiset<pair<int, int>> time_itervals;
        
        for (auto v : intervals){
            time_itervals.insert({v[0], 1});
            time_itervals.insert({v[1], 0});
        }
        
        int curr_room = 0;
        int res = 0;
        
        for (auto time_interval : time_itervals){
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