class Solution {
public:
    int isPrime(int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        
        for (int i = 3; i < sqrt(n) + 1; i += 2){
            if (n % i == 0) return 0;
        }
        return 1;
    }
    
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int res = 1;
        for(int i = 3; i < n; i += 2){
            if (isPrime(i)) res ++;
        }
        return res;
    }
};