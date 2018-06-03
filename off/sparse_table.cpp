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
#define MAX 100000
#define LOGMAX 17

int query(const int matrix[MAX][LOGMAX], const int data[MAX], int n, int qs, int qe){
    int k = (int)log2(qe - qs + 1);

    // Get two intervals with same size that overlaps all the query range
    if (data[matrix[qs][k]] < data[matrix[qe - (1 << k) + 1][k]])
        return matrix[qs][k];
    return matrix[qe - (1 << k) + 1][k];
}

void pre_process(int matrix[MAX][LOGMAX], const int data[MAX], int n){
    for (int i = 0 ; i < n; ++i){
        matrix[i][0] = i;                               // Base case
    }
    for (int j = 1; (1 << j) <= n; ++j){                // Power of 2: 1, 2, 4 ... 
        for (int i = 0; i + (1 << j) - 1 < n; ++i){     
            if (data[matrix[i][j-1]] < data[matrix[i + (1 << j - 1)][j-1]]){    
                matrix[i][j] = matrix[i][j-1];
            } else {
                matrix[i][j] = matrix[i + (1 << j - 1)][j-1];
            }
        }
        cout << j << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL); 

    int data[MAX], matrix[MAX][LOGMAX];
    int n;
    cin >> n;
    for (int i = 0 ; i < n; ++i){
        cin >> data[i];
    }
    pre_process(matrix, data, n);

    for (int j = 0; 1 << j <= n; ++j ){
        for (int i = 0; i + (1 << j) - 1 < n; ++i){
            cout << matrix[i][j] << spc;
        }
        cout << endl;
    }
    while(1){
        int qs, qe;
        cin >> qs >> qe;
        cout << query(matrix, data, n, qs, qe) << endl;
    }


}