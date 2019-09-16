class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int oddCounter = 0;
        int evenCounter = 0;
        vector<int> res = vector<int>(A.size());
        
        for (int num : A){
            if (num % 2){
                oddCounter++;
            } else {
                evenCounter++;
            }
        }
        if (oddCounter > evenCounter){
            for (int num : A){
                if (num % 2){
                    oddCounter--;
                    res[2*oddCounter] = num;
                } else {
                    evenCounter--;
                    res[2*evenCounter + 1] = num;
                }
            }
        } else {
            for (int num : A){
                if (num % 2){
                    oddCounter--;
                    res[2*oddCounter + 1] = num;
                } else {
                    evenCounter--;
                    res[2*evenCounter] = num;
                }
            }
        }
        return res;
    }
};