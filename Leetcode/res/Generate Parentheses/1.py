\*
Author: allannozomu
Runtime: 44 ms
Memory: 13.4 MB*\

class Solution:
    solution = 
    size = 0
    
    def parenthese(self, s, left, right):
        if len(s) == (self.size << 1):
            self.solution.append(s)
            return
        if left:
            self.parenthese(s + '(', left - 1, right)
        if left < right:
            self.parenthese(s + ')', left, right - 1)
    
    def generateParenthesis(self, n: int) -> List[str]:
        self.solution = 
        self.size = n
        self.parenthese('', n, n)
        return self.solution