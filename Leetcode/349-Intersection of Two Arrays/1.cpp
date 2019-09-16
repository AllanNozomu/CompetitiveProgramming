class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        
        unordered_set<int> appeared;
        for (int num : nums1){
            appeared.insert(num);
        }
        for (int num : nums2){
            if (appeared.find(num) != appeared.end()){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};