\*
Author: allannozomu
Runtime: 9120 ms
Memory: 109.1 MB*\

class Solution:
    dp = {}
    longest = (0,0)
    
    def longestPalindrome(self, s: str) -> str:
        dp = {}
        longest = (0,0)
        s = s
        for i in range(len(s) - 1):
            dp[i,i] = True
            if s[i] == s[i + 1]:
                longest = (i, i+1)
                dp[i,i+1] = True
            else:
                dp[i,i+1] = False
        dp[len(s) - 1, len(s) - 1] = True

        for i in range(2, len(s)):
            for j in range(len(s) - i):
                if (s[j] == s[j + i] and dp[j + 1, j + i - 1]):
                    dp[j, j+ i] = True
                    longest = (j, j+i)
                else:
                    dp[j, j+ i] = False
        return s[longest[0] : longest[1] + 1]