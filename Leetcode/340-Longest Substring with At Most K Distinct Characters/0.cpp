class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s == "" || k == 0) return 0;
        
        int slow, fast;
        int different_counter = 1;
        int maximum = 1;
        
        unordered_map<char, int> char_counter;
        char_counter[s[0]] = 1;
        
        for(slow = 0, fast = 1; fast < s.size(); ++fast){
            char curr = s[fast];
            if (!char_counter[curr]){
                different_counter++;
                while (different_counter > k){
                    char slow_c = s[slow];
                    char_counter[slow_c]--;
                    slow++;
                    if (!char_counter[slow_c]) different_counter--;
                }
            }
            char_counter[curr]++;
            maximum = max(maximum, fast - slow + 1);
        }
        
        return maximum;
    }
};