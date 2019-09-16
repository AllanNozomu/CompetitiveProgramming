#include<bits/stdc++.h>
#define mkp(a,b) make_pair(a,b)

using namespace std;


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    unordered_map<int, pair<char, int>> quebra;

    for (int i = 0 ; i < N; ++i){
        int l, r;
        char c;
        cin >> l >> c >> r;
        quebra[l] = mkp(c, r);
    }

    pair<char, int> peca = quebra[0];

    while(peca.second != 1){
        cout << peca.first; 
        peca = quebra[peca.second];
    }
    cout << peca.first;
    cout << endl;
}