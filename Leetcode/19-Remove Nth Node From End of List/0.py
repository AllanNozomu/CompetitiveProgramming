# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEndAux(self, now, n):
        if now.next == None:
            if n == 1:
                return (2, None)
            return (2, now)
        pos, next_node = self.removeNthFromEndAux(now.next, n)
        if pos == n:
            return (pos + 1, next_node)
        now.next = next_node
        return (pos + 1, now)
    
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        pos, head = self.removeNthFromEndAux(head, n)
        return head
        
            