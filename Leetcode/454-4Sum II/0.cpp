class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> AB;
        
        for (int a : A){
            for(int b : B){
                AB[a+b]++;
            }
        }
        int count = 0;
        for(int c : C){
            for(int d : D){
                count += AB[-(c+d)];
            }
        }
        return count;
    }
};