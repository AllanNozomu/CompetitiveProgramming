#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int N, P;
    cin >> N >> P;
    
    while(N && P){
        vector<int> numeros;
        unordered_map<int, int> quantidades;
        
        for (int i = 0 ; i < N; ++i){
            int num ;
            cin >> num;
            if (quantidades[num]){
                quantidades[num]++;
            } else {
                quantidades[num] = 1;
                numeros.push_back(num);
            }
        }
        int resposta = 0;
        for(auto num : numeros){
            if (quantidades[num] >= P){
                resposta++;
            }
        }
        cout << resposta << endl;
        
        cin >> N >> P;
    }
 
    return 0;
}