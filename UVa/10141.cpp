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

#define umap unordered_map
#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

clock_t t = clock();

void check_time(){
    t = clock() - t;
    cout << "Time taken " << ((double)t)/CLOCKS_PER_SEC << "s" << endl ;
}

template <typename C, typename D>
void print_pair(const pair<C, D> & par){
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
    string dump;

    int N, P, t = 1;
    cin >> N >> P;
    getline(cin, dump);
    
    while(N){
        float best_price;
        int best_matches = -1;
        string best_name;

        for (int i = 0 ; i < N; ++i){
            getline(cin, dump);
        }

        for (int i = 0 ; i < P; ++i){
            string name;
            float price;
            int matches;

            getline(cin, name);
            cin >> price >> matches;
            getline(cin, dump);

            for (int j = 0 ; j < matches; ++j){
                getline(cin, dump);
            }
            if (matches > best_matches){
                best_matches = matches;
                best_price = price;
                best_name = name;
            } else if (matches == best_matches && price < best_price) {
                best_price = price;
                best_name = name;
            }
        }
        if (t > 1) printf("\n");
        printf("RFP #%d\n%s\n", t++, best_name.c_str());

        cin >> N >> P;
        getline(cin, dump);
    }

}
