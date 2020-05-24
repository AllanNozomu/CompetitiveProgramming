# Author: allannozomu
# Runtime: 76 ms
# Memory: 13.4 MB

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        program = re.compile('^{}$'.format(p))
        if program.match(s):
            return True
        return False