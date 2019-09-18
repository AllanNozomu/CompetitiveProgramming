#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<char> > mapa;
vector<vector<bool> > visited;

int qte = 0;

void dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (visited[x][y]) return;
    if (mapa[x][y] != '.') return;

    visited[x][y] = true;

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main()
{
    cin >> N >> M;

    mapa = vector<vector<char> >(N, vector<char>(M));
    visited = vector<vector<bool> >(N, vector<bool>(M, false));

    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            cin >> mapa[i][j];
        }
    }

    for (int i = 0 ; i < N; ++i){
        for (int j = 0 ; j < M; ++j){
            if (mapa[i][j] == '.' && !visited[i][j]){
                dfs(i,j);
                qte ++;
            }
        }
    }
    cout << qte << endl;

}