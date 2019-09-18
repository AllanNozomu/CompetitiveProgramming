#include<bits/stdc++.h>

using namespace std;

int main(){
  long long int sacos, comp, min_t, all = 0;

  cin >> sacos >> comp >> min_t;
  vector<long long int> pipocas(sacos);

  for (int i = 0; i < sacos; ++i){
    cin >> pipocas[i];
    all += pipocas[i];
  }  
  long long int left = 0;
  long long int right = all;
  long long mid = (left + right) / 2; 

  while (left < right){
    int i = 0;
    int acc = 0;
    for (int c = 0; c < comp; ++c){
      for (; acc + pipocas[i] <= mid * min_t && i < sacos; ++i){
          acc += pipocas[i];
      } 
      acc = 0;
    }
    if (i == sacos) {
      right = mid;
    } else {
      left = mid + 1;
    }
    mid = (left + right) / 2; 
  }
 
  cout << mid << endl;
  return 0;
}