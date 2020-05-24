# Author: allannozomu
# Runtime: 72 ms
# Memory: 14.6 MB

class Solution:
    def maxArea(self, height: List[int]) -> int:
        ini = 0
        end = len(height) - 1
        biggest = 0
        while(ini <= end):
            biggest = max(biggest, min(height[ini], height[end]) * (end - ini))
            if (height[ini] < height[end]):
                ini += 1
            else:
                end -= 1
        return biggest
        