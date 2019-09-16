class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() == 0 || A.size() == 1) return 1;
        
        int prev = A[0];
        int increasing = -1;
        for (int i = 1; i < A.size(); ++i){
            int curr = A[i];
            if (prev < curr){
                if (increasing == -1) 
                    increasing = 1;
                else if (!increasing) return 0;
            } else if (prev > curr){
                if (increasing == -1) 
                    increasing = 0;
                else if (increasing) return 0;
            }
            prev = curr;
        }
        return 1;
    }
};