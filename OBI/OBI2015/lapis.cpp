#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mkp(a,b) make_pair(a,b)

int N;
vector<vector<char>> grid;

int in_bounds (pii pos){
    if (pos.first >= 0 && pos.second >= 0 && pos.first < N && pos.second < N)
        return 1;
    return 0;
}

vector<pii> avaiable_pairs(pii pos){
    vector<pii> res;

    pii new_pos = mkp(pos.first - 1, pos.second);
    if (in_bounds(new_pos)){
        if (grid[new_pos.first][new_pos.second] == '*')
            res.push_back(new_pos);
    }
    new_pos = mkp(pos.first, pos.second - 1);
    if (in_bounds(new_pos)){
        if (grid[new_pos.first][new_pos.second] == '*')
            res.push_back(new_pos);
    }
    new_pos = mkp(pos.first + 1, pos.second);
    if (in_bounds(new_pos)){
        if (grid[new_pos.first][new_pos.second] == '*')
            res.push_back(new_pos);
    }
    new_pos = mkp(pos.first, pos.second + 1);
    if (in_bounds(new_pos)){
        if (grid[new_pos.first][new_pos.second] == '*')
            res.push_back(new_pos);
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> N;

    grid = vector<vector<char>>(N, vector<char>(N));

    queue<pii> fila;

    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < N; ++j){
            cin >> grid[i][j];
            if (grid[i][j] == '0') {
                fila.push(mkp(i, j));
            }
        }
    }

    while(!fila.empty()){
        pii pos = fila.front();
        fila.pop();

        int number = grid[pos.first][pos.second] - '0';
        if (number == 8) break;
        for (auto viz : avaiable_pairs(pos)){
            if (grid[viz.first][viz.second] == '*'){
                fila.emplace(viz);
                grid[viz.first][viz.second] = '0' + min(9, number + 1);
            }
        }
    }
    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < N; ++j){
            if (grid[i][j] == '*'){
                cout << 9;
            } else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }

}