#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int reais, centavos;
    char c;

    cin >> reais >> c >> centavos;

    cout << "NOTAS:" << endl;
    cout << reais / 100 << " nota(s) de R$ 100.00" << endl;
    reais %= 100;
    cout << reais / 50 << " nota(s) de R$ 50.00" << endl;
    reais %= 50;
    cout << reais / 20  << " nota(s) de R$ 20.00" << endl;
    reais %= 20;
    cout << reais / 10  << " nota(s) de R$ 10.00" << endl;
    reais %= 10;
    cout << reais / 5  << " nota(s) de R$ 5.00" << endl;
    reais %= 5;
    cout << reais / 2 << " nota(s) de R$ 2.00" << endl;
    reais %= 2;
    cout << "MOEDAS:" << endl;
    cout << reais << " moeda(s) de R$ 1.00" << endl;

    cout << centavos / 50 << " moeda(s) de R$ 0.50" << endl;
    centavos %= 50;
    cout << centavos / 25 << " moeda(s) de R$ 0.25" << endl;
    centavos %= 25;
    cout << centavos / 10 << " moeda(s) de R$ 0.10" << endl;
    centavos %= 10;
    cout << centavos / 5 << " moeda(s) de R$ 0.05" << endl;
    centavos %= 5;
    cout << centavos <<" moeda(s) de R$ 0.01" << endl;
}