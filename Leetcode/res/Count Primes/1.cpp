\*
Author: allannozomu
Runtime: 204 ms
Memory: 10.9 MB*\

class Solution {
private:
    vector<int> primes;
public:
    int isPrime(int n){
        if (n < 2) return 0;
        if (n == 2) return 1;
        
        for (int prime : primes){
            if (prime > sqrt(n) + 1){
                break;
            }
            if (n % prime == 0) return 0;
        }
        primes.push_back(n);
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