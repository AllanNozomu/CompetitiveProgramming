#include<bits/stdc++.h>

using namespace std;

int main(){
  int n, m;
  int p1, p2;
  int r1, r2;

  cin >> n >> m >> p1 >> p2 >> r1 >> r2;

  n = n / 2 + 1;
  m = m / 2 + 1;

  p1 = p1 / 2 + 1;
  p2 = p2 / 2 + 1;

  r1 = r1 / 2 + 1;
  r2 = r2 / 2 + 1;

  int total = n * m;
  int p = (p1 + p2) % 2;
  int r = (r1 + r2) % 2;

  if (total % 2 == 0){
    if (p != r)
      cout << total * 2 - 1;
    else
      cout << total * 2 - 3;
  } else {
    if (p == r && p == 0)
      cout << total * 2 - 1;
    else if (p == r)
      cout << total * 2 - 5;
    else
      cout << total * 2 - 3;
  }
  cout << endl;

  return 0;
}