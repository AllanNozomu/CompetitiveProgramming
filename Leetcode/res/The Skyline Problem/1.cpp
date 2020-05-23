\*
Author: allannozomu
Runtime: 32 ms
Memory: 15.9 MB*\

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<tuple<int, int, int>> events;
        
        for (vector<int> building : buildings){
            events.push_back({building[0], 0, -building[2]});
            events.push_back({building[1], 1, building[2]});
        }
        
        sort(events.begin(), events.end());
        
        int first = true;
        pair<int, int> previous;
        vector<vector<int>> skyline;
        
        multiset<int> heights;
        for (auto event : events){
            int curr_x = get<0>(event);
            int curr_y = get<2>(event);
            
            if (get<1>(event) == 0){
                curr_y *= -1;
                heights.insert(curr_y);
            } else {
                heights.erase(heights.find(curr_y));
            }
            
            if (heights.empty()){
                skyline.push_back({curr_x, 0});
            } else {
                if (previous.second != *heights.rbegin()){
                    skyline.push_back({curr_x, *heights.rbegin()});
                }
            }
            
            previous = {skyline[skyline.size() - 1,0], skyline[skyline.size() - 1,1]};
        }
        
        return skyline;
    }
};