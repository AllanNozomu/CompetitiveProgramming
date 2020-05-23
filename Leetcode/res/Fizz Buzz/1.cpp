\*
Author: allannozomu
Runtime: 8 ms
Memory: 9.9 MB*\

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res = vector<string>(n);
        
        for (int i = 3 ; i <= n; i+=3){
            res[i-1] = "Fizz";
        }
        for (int i = 5 ; i <= n; i+=5){
            res[i-1] += "Buzz";
        }
        for (int i = 1 ; i <= n; i++){
            if (res[i-1] == ""){
                res[i-1] = to_string(i);
            }
        }
        return res;
    }
};