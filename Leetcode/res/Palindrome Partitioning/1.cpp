\*
Author: allannozomu
Runtime: 32 ms
Memory: 29.4 MB*\

class Solution {
private:
    unordered_map<int, vector<vector<string>>> memo;
    
public:
    bool isPalindrome(string& s, int start, int end){                               // O(n)
        while(start < end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    void subPartition(string& s, int start){
        if (start == s.size()){
            memo[start] = {{}};
            return;
        }
        if (memo.find(start) != memo.end())
            return;
        
        vector<vector<string>> res;
        for (int end = start; end < s.size(); ++end){                               // O(n)
            if (isPalindrome(s, start, end)){                                       // O(n)
                subPartition(s, end + 1);
                for (auto &sub_res : memo[end + 1]){                                // O(2^n)
                    res.push_back({s.substr(start, end - start + 1)});
                    res[res.size() - 1].insert(res[res.size() - 1].end(), sub_res.begin(), sub_res.end());
                }
            }
        }
        memo[start] = move(res);
        return;
    }
    
    vector<vector<string>> partition(string s) {
        subPartition(s, 0);
        return memo[0];
    }
};