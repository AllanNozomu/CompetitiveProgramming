#include <bits/stdc++.h>

using namespace std;

int main(){
    int F, R;

    cin >> F >> R;

    vector<int> sementes = vector<int>(R);

    for (int i = 0 ; i < R; ++i){
        cin >> sementes[i];
    }
    sort(sementes.begin(), sementes.end());
    
    int ante = 0;
    int res = 0;

    for (int semente : sementes){
        
        if (ante == 0){
            res = max(res, semente - 1);
        }else{
            res = max(res, (semente - ante) / 2);
        }
        ante = semente;
    }
    res = max(res, F - ante);
    cout << res << endl;
    return 0;
}