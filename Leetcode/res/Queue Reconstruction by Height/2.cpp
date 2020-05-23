\*
Author: allannozomu
Runtime: 88 ms
Memory: 13.2 MB*\

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); ++i){
            people[i,1] *= -1;
        }
        sort(people.rbegin(), people.rend());
        for (int i = 0; i < people.size(); ++i){
            people[i,1] *= -1;
        }
        
        for (auto person : people){
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};