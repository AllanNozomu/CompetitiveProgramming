class Solution {
public:
    static int cmp(int a, int b){
        return a % 2 == 0 && b % 2;
    }
    
    vector<int> sortArrayByParity(vector<int>& A) {
        sort(A.begin(), A.end(), cmp);
        return A;
    }
};