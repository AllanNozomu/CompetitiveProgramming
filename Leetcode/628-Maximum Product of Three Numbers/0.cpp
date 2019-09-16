class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        multiset<int> biggest, lowest;
        
        for (int num : nums){
            if (biggest.size() < 3){
                biggest.insert(num);
            } else if (*biggest.begin() < num){
                biggest.erase(biggest.find(*biggest.begin()));
                biggest.insert(num);
            }
            if (lowest.size() < 2){
                lowest.insert(num);
            }else if (*lowest.rbegin() > num){
                lowest.erase(lowest.find(*lowest.rbegin()));
                lowest.insert(num);
            }
        }
        
        int onlyPositives = 1, twoNegatives = 1;
        for (int num : biggest){
            onlyPositives *= num;
        }
        for (int num : lowest){
            twoNegatives *= num;
        }
        return max(onlyPositives, twoNegatives * *biggest.rbegin());
        
    }
};