class Solution {
public:
    string intToRoman(int num) {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",  "V", "IV", "I"};
        
        string res = "";
        int index = 0;
        while(num > 0){
            if (num >= nums[index]){
                num -= nums[index];
                res += strs[index];
            } else {
                index ++;
            } 
        }
        return res;
    }
};