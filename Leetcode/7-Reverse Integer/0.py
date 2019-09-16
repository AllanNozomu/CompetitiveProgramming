class Solution:
    def reverse(self, x: int) -> int:
        if abs(x) > ((1<<31) - 1):
            return 0
        if x < 0:
            r = int('-'+str(x)[1::][::-1])
        else:
            r = int(str(x)[::-1])
        if abs(r) > ((1<<31) - 1):
            return 0
        return r