#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int v[3];

int main(){
  int n;
  cin >> n;

  while(n--){
    int q;
    cin >> q;
    v[0] = v[1] = v[2] = 0;
    char c, d;
    while(q--){
      cin >> c >> d;
      if (c == 'R'){
        if (d == 'R'){
        } else if (d == 'B'){
          v[0] ++;;
        } else {
          v[0] += 2;
        }
      } else if (c == 'B'){
        if (d == 'R'){
          v[1] += 2;
        } else if (d == 'B'){

        } else {
          v[1]++;
        }
      } else {
        if (d == 'R'){
          v[2]++;
        } else if (d == 'B'){
          v[2]+=2;
        } else {

        }
      }
    }
    if (v[0] == v[1] && v[1] == v[2]){
      cout << "trempate" << endl;
    } else if (v[0] > v[1] && v[0] > v[2]){
      cout << "red" << endl;
    } else if (v[1] > v[0] && v[1] > v[2]){
      cout << "blue" << endl;
    } else if (v[2] > v[0] && v[2] > v[1]){
      cout << "green" << endl;
    } else if (v[0] == v[1] || v[1] == v[2]){
      cout << "empate" << endl;
    }
  }
}