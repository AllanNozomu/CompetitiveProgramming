\*
Author: allannozomu
Runtime: 8 ms
Memory: 10.4 MB*\

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        for (int i = 1 ; i <= n; ++i){
            int res3 = i % 3 == 0;
            int res5 = i % 5 == 0;
            if (res3){
                if (res5){
                   res.push_back("FizzBuzz"); 
                } else {
                   res.push_back("Fizz");  
                }
            } else {
                if (res5){
                    res.push_back("Buzz"); 
                } else {
                    res.push_back(to_string(i)); 
                }
            }
        }
        return res;
    }
};