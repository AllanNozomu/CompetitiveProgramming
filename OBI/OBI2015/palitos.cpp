#include<bits/stdc++.h>

using namespace std;

long long two_ways(long long  n, long long  l){
    long long  resto = n - l;
    if (resto >= 1){
        if (resto > l) {
            return 0;
        } else {
            return l - resto + 1;
        }
    }
    return n - 1;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long  N, L;
    cin >> N >> L;

    long long total = 0;
    for (int i = L; N - i <= 2 * L && i >= 1; i--){
        if (N - i < 2) continue;
        total += two_ways(N-i, L);
    }
    cout << total << endl;
}