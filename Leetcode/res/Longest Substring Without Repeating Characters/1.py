# Author: allannozomu
# Runtime: 88 ms
# Memory: 13.3 MB

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        alphabet = {}
        i = 0 
        lslen = 0
        lsstr = ''
        previous = 0
        
        for i in range(len(s)):
            if s[i] in alphabet and alphabet[s[i]] >= previous:
                if i - previous > lslen:
                    lslen = i - previous
                previous = alphabet[s[i]] + 1
            alphabet[s[i]] = i
        if len(s) - previous > lslen:
            lslen = len(s) - previous
        return lslen