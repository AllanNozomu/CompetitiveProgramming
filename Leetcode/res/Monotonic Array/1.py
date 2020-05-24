# Author: allannozomu
# Runtime: 544 ms
# Memory: 19.8 MB

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        if (A[0] < A[-1]):
            ordered = sorted(A)
        else:
            ordered = sorted(A, reverse = True)
            
        return ordered == A
        