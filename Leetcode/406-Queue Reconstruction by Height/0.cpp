class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); ++i){
            people[i][1] *= -1;
        }
        sort(people.rbegin(), people.rend());
        for (int i = 0; i < people.size(); ++i){
            people[i][1] *= -1;
        }
        
        for (auto person : people){
            int tallers = 0;
            int i = 0;
            for (i = 0 ; i < res.size() && tallers < person[1]; i++){
                
                vector<int> curr_person = res[i];
                if (curr_person[0] >= person[0]){
                    tallers++;
                }
            }
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};