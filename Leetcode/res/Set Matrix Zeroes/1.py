# Author: allannozomu
# Runtime: 112 ms
# Memory: 13.4 MB

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        
        rows = len(matrix)
        if rows == 0:
            return
        
        cols = len(matrix[0])
        for i in range(rows):
            has_zero = False
            for j in range(cols):
                if matrix[i,j] == 0:
                    has_zero = True
            if has_zero:
                for j in range(cols):
                    if matrix[i,j] != 0:
                        matrix[i,j] = 'x'
                        
        for j in range(cols):
            has_zero = False
            
            for i in range(rows):
                if matrix[i,j] == 0:
                    has_zero = True
            if has_zero:
                for i in range(rows):
                    if matrix[i,j] != 0:
                        matrix[i,j] = 'x'
                        
        for i in range(rows):
            for j in range(cols):
                if matrix[i,j] == 'x':
                    matrix[i,j] = 0 
        