#include <bits/stdc++.h>

using namespace std;

int main(){
    int F, R, restantes, dias;

    cin >> F >> R;
    restantes = F;

    vector<int> sementes(R);
    vector<int> visitados = vector<int>(F + 1);

    for (int i = 0 ; i < R; ++i){
        cin >> sementes[i];
        visitados[sementes[i]] = 1;
        restantes--;
    }

    for (dias = 0; restantes > 0; ++dias){
        vector<int> novas_sementes;
        for (int semente : sementes){
            
            // Adiciona semente a esquerda
            if (semente > 1 && !visitados[semente - 1]){
                novas_sementes.push_back(semente - 1);
                visitados[semente - 1] = 1;
                restantes--;
            }
            // Adiciona semente a direita
            if (semente < F && !visitados[semente + 1]){
                novas_sementes.push_back(semente + 1);
                visitados[semente + 1] = 1;
                restantes--;
            }
        }
        // Renova as novas sementes
        sementes = novas_sementes;
    }
    cout << dias << endl;
    return 0;
}