#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, n;
    cin >> N;
    while(N--){
        cin >> n;
        vector<int> notas = vector<int>(n);
        int sum = 0;
        for (int i = 0 ; i < n; ++i){
            cin >> notas[i];
            sum += notas[i];
        }
        int qty = 0;
        for (int i = 0 ; i < n; ++i){
            if (notas[i] > sum / n) qty++;
        }
        printf("%.3lf%%\n", ((float)qty / n) * 100);
    }

}