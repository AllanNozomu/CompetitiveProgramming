#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, M;

  cin >> N >> M;

  vector<bool> vetor = vector<bool>(N, false);

  while(M--){
    int start, jump;
    cin >> start >> jump;
    start--;

    for (int i = start ; i < N; i += jump){
      vetor[i] = true;
    }
    for (int i = start; i >= 0; i -= jump){
      vetor[i] = true;
    }
  }
  for (bool b : vetor){
    cout << (b ? 1 : 0) << endl;
  }

  return 0;
}