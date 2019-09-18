#include <bits/stdc++.h>

using namespace std;

int main()
{
    int salto, num;
    
    // Leitura da primeira linha
    cin >> salto >> num;
    
    // Criacao de um vetor para armazenar as alturas dos canos
    vector<int> canos = vector<int>(num);
    for (int i = 0 ; i < num; ++i){
        // Leitura de cada um dos canos
        cin >> canos[i];
    }
    
    // Comeca no cano 1 porque verifico sempre a posicao anterior
    for (int i = 1 ; i < num; ++i){
        // Verifica se a diferenca entre o cano atual e o cano anterior eh maior do que 
        // o sapo pode aguentar. abs(x) pega a diferenca absoluta, ou seja, transformar numeros
        // negativos em positivos
        if (abs(canos[i] - canos[i-1]) > salto){
            // Se falhou em algum dos canos, printa a resposta e termina o programa
            cout << "GAME OVER" << endl;
            return 0;
        }
    }
    // Se passou em todos os canos, printa a resposta e termina o programa
    cout << "YOU WIN" << endl;
    
    
    return 0;
}