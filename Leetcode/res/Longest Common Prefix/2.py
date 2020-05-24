# Author: allannozomu
# Runtime: 56 ms
# Memory: 13 MB

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        max_length = -1
        for s in strs:
            if max_length < 0:
                max_length = len(s)
            else:
                max_length = min(len(s), max_length)
       
        for i in range(max_length):
            c = ''
            for s in strs:
                if c == '':
                    c = s[i]
                elif c != s[i]:
                    return res
            res += c
        return res
            