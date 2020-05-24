# Author: allannozomu
# Runtime: 116 ms
# Memory: 13.3 MB

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbersAux(self, l1, l2, carry):
        if l1 == None and l2 == None:
            if carry:
                return ListNode(1 if carry else 0)
            return None
        if l1:
            if l2:
                sum_val = l1.val + l2.val + (1 if carry else 0)
            else:
                sum_val = l1.val + (1 if carry else 0)
        else:
            sum_val = l2.val + (1 if carry else 0)
        actual_node = ListNode(sum_val % 10)
        actual_node.next = self.addTwoNumbersAux(l1.next if l1 else None, l2.next if l2 else None, sum_val >= 10)
        return actual_node
        
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.addTwoNumbersAux(l1, l2, 0)