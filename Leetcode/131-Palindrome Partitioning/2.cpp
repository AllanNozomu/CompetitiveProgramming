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
    
    vector<vector<string>> subPartition(string& s, int start){
        if (start == s.size()){
            return {{}};
        }
        if (memo.find(start) != memo.end())
            return memo[start];
        
        vector<vector<string>> res;
        for (int end = start; end < s.size(); ++end){                               // O(n)
            if (isPalindrome(s, start, end)){                                       // O(n)
                for (auto &sub_res : subPartition(s, end + 1)){                     // O(2^n)
                    res.push_back({s.substr(start, end - start + 1)});
                    res[res.size() - 1].insert(res[res.size() - 1].end(), sub_res.begin(), sub_res.end());
                }
            }
        }
        memo[start] = move(res);
        return memo[start];
    }
    
    vector<vector<string>> partition(string s) {
        return subPartition(s, 0);
    }
};