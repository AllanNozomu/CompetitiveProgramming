\*
Author: allannozomu
Runtime: 24 ms
Memory: 12.8 MB*\

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<pair<int, int>> meetings;
        
        for (auto interval : intervals){
            meetings.push_back({interval[1], 0});
            meetings.push_back({interval[0], 1});
        }
        
        sort(meetings.begin(), meetings.end());
        int busy = false;
        for (auto meeting : meetings){
            if (busy && meeting.second == 1) return false;
            if (meeting.second == 0) 
                busy = false;
            else
                busy = true;
            
        }
        return true;
    }
};