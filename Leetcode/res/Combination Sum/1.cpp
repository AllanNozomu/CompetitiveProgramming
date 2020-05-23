\*
Author: allannozomu
Runtime: 16 ms
Memory: 9.6 MB*\

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> empty;
        visit(empty, 0, 0, candidates, target, res);
        return res;
    }
    
    void visit(vector<int> &current, int sum, int pos, vector<int> &candidates, int target, vector<vector<int>>& res){
        if (sum == target){
            res.push_back(current);
            return;
        }
        if (sum > target){
            return;
        }
        for (int i = pos; i < candidates.size(); ++i){
            current.push_back(candidates[i]);
            sum += candidates[i];
            visit(current, sum, i, candidates, target, res);
            current.pop_back();
            sum -= candidates[i];
        }
    }
};