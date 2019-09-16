#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, B, resp = 0;
    cin >> N >> B;

    vector<int> files = vector<int>(N);

    for(int i = 0 ; i < N; ++i) {
        cin >> files[i];
    }
    sort(files.begin(), files.end());

    for (int l = 0, r = files.size() - 1; l <= r; r--){
        if (files[l] + files[r] <= B){
            l++;
        }
        resp++;
    }
    cout << resp << endl;
}