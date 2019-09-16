class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:   
        nums.sort()
        best = None
        
        for i in range(len(nums) - 2):
            left = i + 1
            right = len(nums) - 1
            while(left < right):
                actual_sum = sum([nums[i], nums[left], nums[right]])
                if best == None or abs(actual_sum - target) < abs(best - target):
                    best = actual_sum
                if (actual_sum > target):
                    right -= 1
                else:
                    left += 1
        return best
