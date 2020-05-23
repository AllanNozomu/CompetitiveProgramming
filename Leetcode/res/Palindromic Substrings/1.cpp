\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.5 MB*\

class Solution {
private:
    int countExpandingInCenter(string& s, int left, int right){
        int count = 0;
        while(s[left] == s[right]){
            count++;
            left--;
            right++;
            if (left < 0 || right >= s.size()) break;
        }
        return count;
    }
    
public:
    int countSubstrings(string s) {
        int count = 0;
        
        for(int i = 0 ; i < s.size(); ++i){
            count += countExpandingInCenter(s, i, i);
            if (i > 0){
                count += countExpandingInCenter(s, i-1, i);
            }
        }
        return count;
    }
};