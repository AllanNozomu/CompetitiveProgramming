class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x = str(x)
        str_x_inverse = str(x)[::-1]
        return str_x == str_x_inverse