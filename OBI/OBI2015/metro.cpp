#include<bits/stdc++.h>

typedef long long ll;
using namespace std;


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> grafo = vector<vector<int>>(N);
    vector<int> sizes = vector<int>(N);
    vector<int> removed = vector<int>(N);

    for (int i = 0 ; i < M; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
        sizes[a]++;
        sizes[b]++;
    }

    queue<int> removables;
    for (int i = 0 ; i < N; ++i){
        int s = sizes[i];
        if (s == 1 || s >= 5){
            removables.push(i);
            removed[i] = 1;
        }
    }

    while(!removables.empty()) {
        int n = removables.front();
        removables.pop();

        for (auto v : grafo[n]){
            sizes[v]--;
            if (sizes[v] == 1 && !removed[v]){
                removed[v] = 1;
                removables.push(v);
            }
        }
    }
    int res =0;
    for(auto n : removed){
        if (n == 0){
            res ++;
        }
    }
    cout << res << endl;
}