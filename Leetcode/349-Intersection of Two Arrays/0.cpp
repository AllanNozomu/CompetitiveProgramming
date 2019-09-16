class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for (int num : nums1){
            if (binary_search(nums2.begin(), nums2.end(), num)){
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};