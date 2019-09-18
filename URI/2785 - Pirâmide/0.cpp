#include<bits/stdc++.h>

using namespace std;
#define MAX 100

int mapa[MAX][MAX];
int dp[MAX][MAX];
int N;

int solve(int line, int start){
    if (line == 0){
        dp[line][start] = mapa[line][start];
        return mapa[line][start];
    }
    if (dp[line][start] > 0){
        return dp[line][start];
    }
    int left = solve(line - 1, start);
    int right = solve(line - 1, start + 1);
    int line_sum = min(left, right);

    for (int i = 0; i < line + 1; ++i){
        line_sum += mapa[line][start + i];
    }

    dp[line][start] = line_sum;
    return line_sum;
}

int main()
{
    cin >> N;

    for (int i = 0 ; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> mapa[i][j];
            dp[i][j] = -1;
        }
    }

    cout << solve(N - 1, 0) << endl;

    return 0;
}