# Author: allannozomu
# Runtime: 44 ms
# Memory: 13.2 MB

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        resp = []
        for num in nums:
            new_resp = 
            for r in resp:
                new_resp.append(r)
                new_resp.append(r + [num])
            resp = new_resp
        return resp