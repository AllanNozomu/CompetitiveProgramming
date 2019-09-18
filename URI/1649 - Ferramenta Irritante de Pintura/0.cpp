#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int v[3];

int main(){
  int n, m, h, w;
  cin >> n >> m >> h >> w;

  while(n && m && h && w) {
    vector<string> mapa = vector<string>(n);

    for (int i = 0 ; i < n; ++i){
      cin >> mapa[i];
    }

    int contador = 0;

    for (int i = 0 ; i <= n - h; ++i){
      for(int j = 0 ; j <= m - w; ++j){
        if (mapa[i][j] == '1'){
          contador++;
          for (int ii = 0; ii < h; ++ii){
            for (int jj = 0 ; jj < w; ++jj){
              if (mapa[i + ii][j + jj] == '1'){
                mapa[i + ii][j + jj]  = '0';
              } else {
                mapa[i + ii][j + jj] = '1';
              }
            }
          }
        }
      }
    }
    int errado = 0;
    for (int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        if (mapa[i][j] == '1')
          errado = 1;
      }
    }
    if (errado)
      cout << -1 << endl;
    else
      cout << contador << endl;

    cin >> n >> m >> h >> w;
  }
}