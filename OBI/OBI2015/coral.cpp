#include<bits/stdc++.h>

using namespace std;


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c || b == d){
        cout << 'V' << endl;
    } else {
        cout << 'F' << endl;
    }
}