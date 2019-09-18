#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int NN = 0; NN < N; ++NN){
        int n, m;

        cin >> n >> m;

        queue<int> q;

        for (int i = 1; i <= n; ++i){
            q.push(i);
        }
        int counter = m;
        while(q.size() > 1){
            int curr = q.front();
            q.pop();

            if (--counter == 0){
                counter = m;
            } else {
                q.push(curr);
            }
        }
        cout << "Case " << NN + 1 << ": " << q.front() << endl;
    }
    /*
    3
    5 2
    6 3
    1234 233
    */
}