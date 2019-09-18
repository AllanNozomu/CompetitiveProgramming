#include <bits/stdc++.h>

using namespace std;

bool triangulo(int menor1, int menor2, int maior){
    if (menor1 + menor2 > maior){
        return true;
    }
    return false;
}

int main(){
    vector<int> numeros = vector<int>(4);
    
    cin >> numeros[0] >> numeros[1] >> numeros[2] >> numeros[3];

    sort(numeros.begin(), numeros.end());

    if (triangulo(numeros[0],numeros[1],numeros[2]) || triangulo(numeros[1],numeros[2],numeros[3])) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }

    return 0;
}