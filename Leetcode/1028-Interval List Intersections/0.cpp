class Solution {

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int index_a = 0, index_b = 0;
        int closing_a = false, closing_b = false;
        vector<vector<int>> answer;
        
        while(index_a < A.size() && index_b < B.size()){
            auto interval_a = A[index_a];
            auto interval_b = B[index_b];
            
            int curr_time_a = closing_a ? interval_a[1] : interval_a[0];
            int curr_time_b = closing_b ? interval_b[1] : interval_b[0];
            
            if (curr_time_a < curr_time_b || (curr_time_a == curr_time_b && !closing_a)){
                if (closing_a){
                    index_a++;
                    if (closing_b){
                        answer.push_back({max(interval_a[0], interval_b[0]), curr_time_a});
                    }
                }
                closing_a = !closing_a;
            } else {
                if (closing_b){
                    index_b++;
                    if (closing_a){
                        answer.push_back({max(interval_a[0], interval_b[0]), curr_time_b});
                    }
                }
                closing_b = !closing_b;
            }
        }
        return answer;
    }
};