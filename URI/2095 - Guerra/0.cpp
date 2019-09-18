#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    vector<int> inimigos = vector<int>(num);
    vector<int> amigos = vector<int>(num);;
    
    for (int i = 0 ; i < num; ++i){
        cin >> inimigos[i];
    }
    for (int i = 0 ; i < num; ++i){
        cin >> amigos[i];
    }
    sort(inimigos.begin(), inimigos.end());
    sort(amigos.begin(), amigos.end());
    
    int indice = 0;
    int vitorias = 0;
    long long amigo;
    for (int inimigo : inimigos){
        bool venceu = false;
        while(indice < num && !venceu){
            amigo = amigos[indice];
            if (amigo > inimigo){
                vitorias++;
                venceu = true;
            }
            indice++;
        }
    }
    
    cout << vitorias << endl;


    return 0;
}