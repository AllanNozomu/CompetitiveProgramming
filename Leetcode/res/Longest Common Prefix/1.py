# Author: allannozomu
# Runtime: 44 ms
# Memory: 12.9 MB

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not len(strs):
            return ''
        res = ''
        i = 0

        while(True):
            c = ''
            for s in strs:
                if i >= len(s):
                    return res
                if c == '':
                    c = s[i]
                if c != s[i]:
                    return res
            res += c
            i += 1
        return res
            