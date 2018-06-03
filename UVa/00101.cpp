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
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<pii>> vvii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

clock_t t = clock();

void check_time(){
    t = clock() - t;
    cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
}

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

int main() 
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vi parents = vi(N, -1);
    vi childrens = vi(N, -1);
    vi piles = vi(N);

    for (int i = 0; i < N; ++i){
        piles[i] = i;
    }

    string cmd;
    cin >> cmd;
    while(cmd != "quit"){
        string cmd2;
        int a, b;
        cin >> a >> cmd2 >> b;
        
        int legal = a != b;
        for (int j = parents[a]; j >= 0; j = parents[j]){
            if (j == b){
                legal = 0;
                break;
            }
        }
        for (int j = parents[b]; j >= 0; j = parents[j]){
            if (j == a){
                legal = 0;
                break;
            }
        }
        if (legal){
            piles[a] = -1;
            print_container(parents);
            print_container(childrens);
            if (childrens[a] >= 0)
                parents[childrens[a]] = -1;

            if (cmd == "move"){
                if (cmd2 == "over"){
                    for (int k = parents[a]; k >= 0;){
                        int next = parents[k];
                        piles[k] = k;
                        parents[k] = -1;
                        childrens[k] = -1;
                        k = next;
                    }
                    parents[a] = -1;

                    int k;
                    for (k = b; parents[k] >= 0; k = parents[k]);
                    parents[k] = a;
                    childrens[a] = k;
                    
                } else {
                    for (int k = parents[b]; k >= 0;){
                        int next = parents[k];
                        piles[k] = k;
                        childrens[k] = -1;
                        parents[k] = -1;
                        k = next;
                    }
                    for (int k = parents[a]; k >= 0;){
                        int next = parents[k];
                        piles[k] = k;
                        childrens[k] = -1;
                        parents[k] = -1;
                        k = next;
                    }
                    parents[a] = -1;

                    parents[b] = a;
                    childrens[a] = b;
                }
            } else {
                if (cmd2 == "over"){
                    int k;
                    for (k = b; parents[k] >= 0; k = parents[k]);
                    parents[k] = a;
                    childrens[a] = k;
                } else {
                    for (int k = parents[b]; k >= 0;){
                        int next = parents[k];
                        piles[k] = k;
                        childrens[k] = -1;
                        parents[k] = -1;
                        k = next;
                    }
                    parents[b] = a;
                    childrens[a] = b;
                }
            }     
        }
        cin >> cmd;
    }
    for (int i = 0 ; i < N; ++i){
        cout << i << ":";
        for (int k = piles[i]; k >= 0; k = parents[k]){
            cout << spc << k;
        } cout << endl;
    }

}
