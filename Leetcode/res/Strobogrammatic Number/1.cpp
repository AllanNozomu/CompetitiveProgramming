\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.3 MB*\

class Solution {
public:
    int compareStrobogrammatic(char a, char b){
        int m = min(a, b);
        int M = max(a, b);
        if (m == '6' && M == '9') return true;
        if (m == '0' && M == '0') return true;
        if (m == '1' && M == '1') return true;
        if (m == '8' && M == '8') return true;
        
        return false;
    }
    bool isStrobogrammatic(string num) {
        for (int left = 0, right = num.size() - 1; left <= right; ++left, --right){
            if (!compareStrobogrammatic(num[left], num[right])) return false;
        }
        return true;
    }
};