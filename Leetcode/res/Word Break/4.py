# Author: allannozomu
# Runtime: 40 ms
# Memory: 13.9 MB

class Solution:
    
    def word_break_aux(self, s: str, wordDict: List[str], dp) -> bool:
        if (len(s) == 0):
            return True
        
        if s in dp:
            return dp[s]
        
        for word in wordDict:
            if word == s[0:len(word)]:
                if self.word_break_aux(s[len(word):], wordDict, dp):
                    return True
                
        dp[s] = False
        return False
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = {}
        return self.word_break_aux(s, wordDict, dp)