#include<bits/stdc++.h>

using namespace std;

int val;
vector<int> qtys = vector<int> (6);
int dp[6][5001] = {0};
int notas[] = {2,5,10,20,50,100};

void solve(int n){
    dp[n][0] = 1;
    dp[n][1] = 0;

    int nota = notas[n];

    for (int i = 2; i <= val; ++i) {
        dp[n][i] = dp[n-1][i];

        for (int q = min(qtys[n], i / nota); q > 0; --q){
            int target = i - q * nota;
            if (i != target)
                dp[n][i] += dp[n-1][target];
        }
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> val;

    for (int i = 0 ; i < qtys.size(); ++i){
        cin >> qtys[i];
    }

    for (int q = min(qtys[0], val / 2); q >= 0; --q){
        dp[0][2*q] = 1;
    }
    solve(1);
    solve(2);
    solve(3);
    solve(4);
    solve(5);
    
    cout << dp[5][val] << endl;
}