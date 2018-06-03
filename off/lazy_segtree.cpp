bool debug = true;

#include<vector>
#include<stack>
#include<map>
#include<bitset>
#include<unordered_map>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

typedef pair<int,int> pii;

#define mkp(a,b) make_pair(a,b)
#define spc " "
#define all(container) container.begin(), container.end()

#define MID (ss + se) / 2
#define LEFT 2 * si + 1
#define RIGHT 2 * si + 2
#define IS_LEAF ss == se

void solve_lazy(vector<int> &st, vector<int> &lazy, int ss, int se, int si){
    if (lazy[si]){
        st[si] = (se - ss + 1) * lazy[si];

        if (!IS_LEAF){
            lazy[LEFT] += lazy[si];
            lazy[RIGHT] += lazy[si];
        }
        lazy[si] = 0;
    }
}

int get_sum(vector<int> &st, vector<int> &lazy, int ss, int se, int qs, int qe, int si){
    solve_lazy(st, lazy, ss, se, si);

    if (qs <= ss && se <= qe)       // In range
        return st[si];

    if (qs > se || qe < ss)         // Out of range
        return 0;
    
    return get_sum(st, lazy, ss, MID, qs, qe, LEFT) + 
            get_sum(st, lazy, MID + 1, se, qs, qe, RIGHT);
}

int get_sum(vector<int> &st, vector<int> &lazy, int n, int qs, int qe){
    return get_sum(st, lazy, 0, n - 1, qs, qe, 0);
}

void update_range(vector<int> &st, vector<int> &lazy, int ss, int se, int us, int uf, int val, int si){
    solve_lazy(st, lazy, ss, se, si);

    if (ss > se || ss > uf || se < us)     // Out of range
        return;
    
    if (IS_LEAF)                          // Update usign bottom-up
        st[si] += val;
    else {
        update_range(st, lazy, ss, MID, us, uf, val, LEFT);
        update_range(st, lazy, MID + 1, se, us, uf, val, RIGHT);

        st[si] = st[LEFT] + st[RIGHT];
    }
}

void update_range(vector<int> &st, vector<int> &lazy, int n, int us, int uf, int val){
    update_range(st, lazy, 0, n - 1, us, uf, val, 0);
}

int construct_segtree(vector<int> &st, const vector<int> &arr, int ss, int se, int si){
    if (IS_LEAF){
        st[si] = arr[ss];                   // Insert leaf node value
    } else {                                // Constuct tree using bottom-up
        st[si] = construct_segtree(st, arr, ss, MID, LEFT) + 
                construct_segtree(st, arr, MID + 1, se, RIGHT);
    }   
    return st[si];
}

void construct_segtree(vector<int> &st, vector<int> &lazy, const vector<int> &arr){
    int x = (int)(ceil(log2(arr.size())));  // log2(n)
    int max_size = 2 * (int)pow(2, x) - 1;  // Max size = 2 * log2(n) - 1
    st = vector<int>(max_size);
    lazy = vector<int>(max_size);

    construct_segtree(st, arr, 0, arr.size() - 1, 0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    vector<int> input, st, lazy;
    int n;
    cin >> n;
    for (int i = 0 ; i < n; ++i){
        int q;
        cin >> q;
        input.emplace_back(q);
    }
    construct_segtree(st, lazy, input);
    for (const auto &value : st){
        cout << value << " ";
    }
    cout << endl;

    for (const auto &value : st){
        cout << value << " ";
    }
    cout << endl;

    int i,j;
    cin >> i >> j;
    while(i >= 0 && j >= 0){
        cout << get_sum(st, lazy, input.size(), i, j) << endl;
        cin >> i >> j;
    }

}