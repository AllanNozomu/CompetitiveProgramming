bool debug = false;

#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<bitset>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

void print_pair(const pii & par){
    if (!debug) return;
    cout << "(" << par.first << spc << par.second << ")" << spc;
}

template <typename C>
void print_array(const C &data, int n){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (int i = 0; i < n; ++i){
        cout << data[i] << spc;
    }
    cout << endl;
}

template <typename C>
void print_container(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        cout << v << spc;
    }
    cout << endl;
}

template <typename C>
void print_pairs(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &v : data){
        print_pair(v);
    }
    cout << endl;
}

template <typename C>
void print_matrix(const C &data){
    if (!debug) return;
    cout << "[DEBUG] " << endl;
    for (const auto &row : data){
        for (const auto &v : row){
            cout << v << spc;
        } cout << endl;
    }
    cout << endl;
}

int N, M;
vvi graph, pieces, rGraph, resp;
vi visited, parent, L, R;

void paint(int index, int distance){
    if (distance % 2){
        L.emplace_back(index);
    } else {
        R.emplace_back(index);
    }
    
    visited[index] = 1;
    for (auto v : graph[index]){
        if (!visited[v])
            paint(v, distance + 1);
    }
}

int main()
{
    vs mapa = vs(2);
    cin >> mapa[0];
    cin >> mapa[1];

    ll contador = 0;

    for (int i = 0 ; i < mapa[0].size(); ++i){
        if (i == 0){
            if (mapa[0][i] == '0' && mapa[0][i + 1] == '0' && mapa[1][i] == '0'){
                contador++;
                mapa[0][i] = 'X';
                mapa[0][i + 1] = 'X';
                mapa[1][i] = 'X';
            }
            if (mapa[1][i] == '0' && mapa[1][i + 1] == '0' && mapa[0][i] == '0'){
                contador++;
                mapa[1][i] = 'X';
                mapa[1][i + 1] = 'X';
                mapa[0][i] = 'X';
            }
        } else if (i == mapa[0].size() - 1){
            if (mapa[0][i] == '0' && mapa[0][i - 1] == '0' && mapa[1][i] == '0'){
                contador++;
                mapa[0][i] = 'X';
                mapa[0][i - 1] = 'X';
                mapa[1][i] = 'X';
            }
            if (mapa[1][i] == '0' && mapa[1][i - 1] == '0' && mapa[0][i] == '0'){
                contador++;
                mapa[1][i] = 'X';
                mapa[1][i - 1] = 'X';
                mapa[0][i] = 'X';
            }
        } else {
            if (mapa[0][i] == '0' && mapa[0][i - 1] == '0' && mapa[1][i] == '0'){
                contador++;
                mapa[0][i] = 'X';
                mapa[0][i - 1] = 'X';
                mapa[1][i] = 'X';
            }
            if (mapa[1][i] == '0' && mapa[1][i - 1] == '0' && mapa[0][i] == '0'){
                contador++;
                mapa[1][i] = 'X';
                mapa[1][i - 1] = 'X';
                mapa[0][i] = 'X';
            }
            if (mapa[0][i] == '0' && mapa[0][i + 1] == '0' && mapa[1][i] == '0'){
                contador++;
                mapa[0][i] = 'X';
                mapa[0][i + 1] = 'X';
                mapa[1][i] = 'X';
            }
            if (mapa[1][i] == '0' && mapa[1][i + 1] == '0' && mapa[0][i] == '0'){
                contador++;
                mapa[1][i] = 'X';
                mapa[1][i + 1] = 'X';
                mapa[0][i] = 'X';
            }
            
        }
    }
    cout << contador << endl;
}
