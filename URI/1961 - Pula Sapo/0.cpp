#include <bits/stdc++.h>

using namespace std;

int main()
{
    int salto, num;
    
    cin >> salto >> num;
    
    vector<int> canos = vector<int>(num);
    for (int i = 0 ; i < num; ++i){
        cin >> canos[i];
    }
    
    for (int i = 1 ; i < num; ++i){
        if (abs(canos[i] - canos[i-1]) > salto){
            cout << "GAME OVER" << endl;
            return 0;
        }
    }
    cout << "YOU WIN" << endl;
    
    
    return 0;
}