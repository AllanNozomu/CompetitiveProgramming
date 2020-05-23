\*
Author: allannozomu
Runtime: 40 ms
Memory: 10.7 MB*\

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {        
        int left_higher = A[0];
        int left_lower = A[0];
        int curr_higher = A[0];
        int answer = 1;
        
        for (int i = 1; i < A.size(); ++i){
            int num = A[i];
            if (num < left_higher){
                answer = i + 1;
                left_higher = curr_higher;
            }
            curr_higher = max(curr_higher, num);
        }
        return answer;
    }
};