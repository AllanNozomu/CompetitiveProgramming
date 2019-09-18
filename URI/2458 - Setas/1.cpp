#include <bits/stdc++.h>

using namespace std;

#define MAX 500

bool visitado[MAX][MAX];
bool safe[MAX][MAX];
char mapa[MAX][MAX];
int N;

bool percorre(int i, int j){
    if (i < 0 || j < 0 || i >= N || j >= N){
        return false;
    }

    if (visitado[i][j]){
        return safe[i][j];
    }

    visitado[i][j] = true;
    bool res;
    switch(mapa[i][j]){
        case '<': 
            res = percorre(i, j - 1);
            break;
        case '>':
            res = percorre(i, j + 1);
            break;
        case 'A':
            res = percorre(i -1, j);
            break;
        case 'V':
            res = percorre(i + 1, j);
            break;
    }
    safe[i][j] = res;
    return safe[i][j];
}

int main(){
    cin >> N;

    for (int i = 0 ; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cin >> mapa[i][j];
            visitado[i][j] = false;
            safe[i][j] = true;
        }
    }

    int res = 0;
    for (int i = 0 ; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (!visitado[i][j]){
                percorre(i, j);
            }
            if (safe[i][j]){
                res ++;
            }
        }
    }
    cout << res << endl;

    return 0;
}