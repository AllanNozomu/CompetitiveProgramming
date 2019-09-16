# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        headNode = ListNode(-1)
        actualNode = headNode
        while l1 and l2:
            if l1.val < l2.val:
                actualNode.next = l1
                l1 = l1.next
            else:
                actualNode.next = l2
                l2 = l2.next
            actualNode = actualNode.next
            
        if l1:
            actualNode.next = l1
        if l2:
            actualNode.next = l2
        return headNode.next