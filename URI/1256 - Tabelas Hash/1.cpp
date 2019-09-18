#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int v[3];

int main(){
  int n, q;

  cin >> n;
  while(n--){
    int k, q;
    cin >> k >> q;
    unordered_map<int,vector<int> > mapa;

    while (q--){
      int v;
      cin >> v;
      mapa[v%k].push_back(v);
    }
    for (int i = 0 ; i < k; ++i){
      printf("%d", i);
      for (auto v : mapa[i]){
        printf(" -> %d", v);
      }
      printf(" -> \\\n");
    }
    if (n > 0)
      printf("\n");
  }
}