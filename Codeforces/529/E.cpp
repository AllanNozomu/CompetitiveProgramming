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

#define umap unordered_map;
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
    std::ios::sync_with_stdio(false);bool debug = false;

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;
    string line;
    cin >> n;
    vi counter = vi(n);
    cin >> line;

    if (n % 2){
        cout << 0 << endl;
        return 0;
    }

    counter[0] = 1;
    for (int i = 1; i < n; ++i){
        if (line[i] == '('){
            counter[i] = counter[i - 1] + 1;
        } else {
            counter[i] = counter[i - 1] - 1;
        }
    }
    if (counter[n-1] == -2) {
        reverse(line.begin(), line.end());
        counter[0] = 1;
        line[0] =  line[0] == '(' ? ')' : '(';
        for (int i = 1; i < n; ++i){
            if (line[i] == ')'){
                line[i] = '(';
                counter[i] = counter[i - 1] + 1;
            } else {
                line[i] = ')';
                counter[i] = counter[i - 1] - 1;
            }
        }
    }
    for (auto c : counter){
        if (c < 0){
            cout << 0 << endl;
            return 0;
        }
    }
    if (counter[n-1] == 2){
        int i;
        for (i = n-1; i >= 0 && counter[i] != 1; --i);
        for (i = i + 1; i < n; ++i){
            if (line[i] == '(')
                ++count;
        }
        cout << count << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
