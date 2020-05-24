# Author: allannozomu
# Runtime: 36 ms
# Memory: N/A

class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        factorial1 = 1;
        factorial2 = 1;
        factorial3 = 1;
        for i in range(2, m):
            factorial1 = factorial1 * i;
            
        for i in range(2, n):
            factorial2 = factorial2 * i;
            
        for i in range(2, m + n - 1):
            factorial3 = factorial3 * i;
        
        return (int)(factorial3 / (factorial1 * factorial2))
        