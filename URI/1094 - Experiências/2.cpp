#include<iostream>

using namespace std;

int v[3];

int main(){
  int n, q;
  char c;
  cin >> n;
  while(n--){
    cin >> q >> c;

    if (c == 'C'){
      v[0]+=q;
    } else if (c == 'R'){
      v[1]+=q;
    } else {
      v[2]+=q;
    }
  }
  int total = v[0] + v[1] + v[2];
  printf("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2f %%\nPercentual de ratos: %.2f %%\nPercentual de sapos: %.2f %%\n", total, v[0], v[1], v[2], (float)v[0] / total * 100.0, (float)v[1]/total*100.0, (float)v[2]/total*100.0);
}