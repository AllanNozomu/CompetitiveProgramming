bool debug = true;

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
typedef vector<pll> vpll;
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

    vector<pair<int, int>> first = vector<pair<int, int>>(4);
    vector<pair<int, int>> second = vector<pair<int, int>>(4);
    vector<pair<int, int>> third = vector<pair<int, int>>(4);

    for (int i = 0; i < 4; ++i){
        cin >> first[i].first >> first[i].second;
        first[i].first += 100;
        first[i].second += 100;
        first[i].first *= 2;
        first[i].second *= 2;
    }

    sort(all(first));

    for (int i = 0; i < 4; ++i){
        cin >> second[i].first >> second[i].second;
        second[i].first += 100;
        second[i].second += 100;
        second[i].first *= 2;
        second[i].second *= 2;
    }

    sort(all(second));

    int half = second[1].first - second[0].first;

    pii esq = second[1], dir = second[1];

    int inside = 0;

    for (int i = 0 ; i <= half && !inside; ++i){
        if (esq.first >= first[0].first && esq.first <= first[3].first && esq.second >= first[0].second && esq.second <= first[3].second)
            inside = 1;
        if (dir.first >= first[0].first && dir.first <= first[3].first && dir.second >= first[0].second && dir.second <= first[3].second)
            inside = 1;

            if (inside){
        print_pair(esq);
        print_pair(dir);
        }

        esq.first --;
        esq.second ++;

        dir.first ++;
        dir.second ++;
    }

    esq = second[2];
    dir = second[2];
    for (int i = 0 ; i <= half && !inside; ++i){
        if (esq.first >= first[0].first && esq.first <= first[3].first && esq.second >= first[0].second && esq.second <= first[3].second)
            inside = 1;
        if (dir.first >= first[0].first && dir.first <= first[3].first && dir.second >= first[0].second && dir.second <= first[3].second)
            inside = 1;

        if (inside){
        print_pair(esq);
        print_pair(dir);
        }

        esq.first --;
        esq.second --;
        
        dir.first ++;
        dir.second --;
    }

    // First inside second
    for (int i = 0 ; i < 4; ++i){
        if (first[i].first >= second[0].first && first[i].first <= second[3].first && first[i].second >= second[0].second && first[i].second <= second[3].second){
            inside = 1;
        }
    }

    cout << (inside ?  "YES" : "NO") << endl;
}
