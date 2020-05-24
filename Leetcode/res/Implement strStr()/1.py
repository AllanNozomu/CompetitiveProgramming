# Author: allannozomu
# Runtime: 48 ms
# Memory: 13.2 MB

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0
        return haystack.find(needle)