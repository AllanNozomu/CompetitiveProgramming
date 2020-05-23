\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.6 MB*\

class Solution {
public:
    string cleanString(string& s){
        string new_string = "";
        for (char c : s){
            if (isdigit(c))
                new_string += c;
            else if (isalpha(c))
                new_string += tolower(c);
            
        }
        return new_string;
    }
    
    bool isPalindrome(string s) {
        if (s == "") return true;
        string new_string = cleanString(s);
        for (int i = 0, j = new_string.size() - 1; i < j; i++, j--){
            if (new_string[i] != new_string[j]) return false;
        }
        return true;
    }
};