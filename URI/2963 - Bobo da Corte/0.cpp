#include <bits/stdc++.h>
 
using namespace std;

int main() {
  int k, carlos;
  cin >> k;
  cin >> carlos; 
  k--;

  while(k--){
    int vote;
    cin >> vote;
    if (vote > carlos){
      cout << "N" << endl;
      return 0;
    }
  }
  
  cout << "S" << endl;
  return 0;
   
}