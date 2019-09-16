#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int is_prime(int n) {
    for (int i = 3; i < sqrt(n); i += 2){
        if (n % i == 0) return 0;
    }
    return 1;
}

vector<int> get_primes(int n){
    vector<int> res;
    res.push_back(2);
    for (int i = 3; i <= n; i += 2){
        if (is_prime(i)) res.push_back(i);
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> primes = get_primes(N);

    int res = 1;
    int original = N;
    for (auto prime : primes){
        N = original;
        int qty = 0;
        while(N % prime == 0){
            N /= prime;
            qty ++;
        }
        res *= qty + 1;
    }

    cout << res << endl;
}