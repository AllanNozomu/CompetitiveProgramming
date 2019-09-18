#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long num;
    cin >> num;
    
    for (int i = 2 ; i <= sqrt(num) + 1; ++i){
        if (num % i == 0){
            cout << "S" << endl;
            return 0;
        }
    }
    cout << "N" << endl;

    return 0;
}