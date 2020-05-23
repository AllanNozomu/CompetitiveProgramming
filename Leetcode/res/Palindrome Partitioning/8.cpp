\*
Author: allannozomu
Runtime: 104 ms
Memory: 124 MB*\

class Solution {
public:
    bool isPalindrome(string& s, int start, int end){
        while(start < end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    vector<vector<string>> subPartition(string& s, int start){
        if (start == s.size()){
            return {{}};
        }
        vector<vector<string>> res;
        for (int end = start; end < s.size(); ++end){
            if (isPalindrome(s, start, end)){
                for (auto sub_res : subPartition(s, end + 1)){
                    vector<string> new_res = {s.substr(start, end - start + 1)};
                    new_res.insert(new_res.end(), sub_res.begin(), sub_res.end());
                    res.push_back(new_res);
                }
            }
        }
        return res;
    }
    
    vector<vector<string>> partition(string s) {
        return subPartition(s, 0);
    }
};