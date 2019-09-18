#include <bits/stdc++.h>

using namespace std;

// Funcao que procura na palavra, determinada letra
bool tem_letra(string palavra, char letra){
    for (char c : palavra){
        if (c == letra)
            return true;
    }
    return false;
}

int main(){
    char letra;
    int qtde_palavras = 0, qtde_com_letra = 0;

    string palavra;

    cin >> letra;

    while(cin >> palavra){
        qtde_palavras++;
        // Biblioteca padrao (posso fazer o tem letra tambem)
        if (find(palavra.begin(), palavra.end(), letra) != palavra.end())
            qtde_com_letra++;
    }

    printf("%.1f\n", float(qtde_com_letra) / qtde_palavras * 100);

    return 0;
}