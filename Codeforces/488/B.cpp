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

int cmpS(pair<int, pii> k1, pair<int, pii> k2){
    return k1.second < k2.second;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, pii>> info = vector<pair<int, pii>>(n);
    set<pii> coins;
    set<pair<int, ll>> resp;

    for (int i = 0; i < n ; ++i){
        info[i].first = i;
        cin >> info[i].second.first;
    }
    for (int i = 0; i < n ; ++i){
        cin >> info[i].second.second;
    }
    sort(all(info), cmpS);

    for (int i = 0 ; i < n; ++i){
        ll res = info[i].second.second;
        int contador = 0;
        for (auto it = coins.begin(); it != coins.end() && contador < k; ++it){
            if (info[i].second.first > it->second){
                res += -it->first;
                contador++;
            }
        }
        coins.emplace(mkp(-info[i].second.second, info[i].second.first));
        resp.emplace(mkp(info[i].first, res));
    }
    for (auto par : resp){
        cout << par.second << spc;
    }
    cout << endl;
}
