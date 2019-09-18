#include<bits/stdc++.h>

using namespace std;
#define MAX 100

// 8
// 1 1 1 3 5 4 8 12

int main()
{
    int N;

    cin >> N;

    if (N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> nums = vector<int>(N);

    for (int i = 0; i < N; ++i) cin >> nums[i];

    int diff = nums[0] - nums[1];
    int count = 1;

    for (int i = 2; i < N; ++i){
        if (nums[i - 1] - nums[i] != diff){
            count ++;
            diff = nums[i - 1] - nums[i];
        }
    }
    cout << count << endl;


    return 0;
}