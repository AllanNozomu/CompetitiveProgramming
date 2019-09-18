#include<bits/stdc++.h>

using namespace std;

int main() {
    int a,b,c,res;
    
    cin >> a >> b >> c;
    
    res = min({
        b * 2 + c * 4,
        a * 2 + c * 2,
        a * 4 + b * 2,
    });
    
    cout << res << endl;
}