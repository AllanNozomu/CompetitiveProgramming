class Solution {
public:
    int value_of_c(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        int number = 0;
        for (int i = 0; i < s.size(); ++i){
            if (i == s.size() - 1){
                number += value_of_c(s[i]);
            } else {
                int now = value_of_c(s[i]);
                int next = value_of_c(s[i + 1]);
                if (now < next)
                    number -= now;
                else 
                    number += now;
            }
        }
        
        return number;
    }
};