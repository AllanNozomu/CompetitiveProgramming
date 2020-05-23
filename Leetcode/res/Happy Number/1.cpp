\*
Author: allannozomu
Runtime: 4 ms
Memory: 8.6 MB*\

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        
        while(n != 1 && visited.find(n) == visited.end()){
            visited.insert(n);
            int new_n = 0;
            while (n){
                new_n += (n % 10) * (n % 10);
                n /= 10;
            }
            n = new_n;
        }
        return n == 1;
    }
};