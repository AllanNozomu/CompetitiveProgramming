class Solution {
public:
    string chars_of_digit(int n){
        switch(n){
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
        }
    }
    
    void letterCombinationsAux(const string& digits, int index, const string& formed_string, vector<string>& results){
        if (index == digits.size()){
            results.push_back(formed_string);
            return;
        }
        
        string chars = chars_of_digit(digits[index]);
        for (char c : chars){
            letterCombinationsAux(digits, index + 1, formed_string + c, results);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        if (digits.size())
            letterCombinationsAux(digits, 0, "", results);
        return results;
    }
};