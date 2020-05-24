# Author: allannozomu
# Runtime: 96 ms
# Memory: 13.4 MB

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        union = nums1 + nums2
        union.sort()
        if (len(union) % 2):
            return union[len(union) // 2]
        return (union[len(union) // 2] + union[len(union) // 2 - 1]) / 2
        