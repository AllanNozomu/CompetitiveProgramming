\*
Author: allannozomu
Runtime: 8 ms
Memory: 8.7 MB*\

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode* actualNode = &head;
        while(l1 != NULL && l2 != NULL){
            if (l1->val < l2->val){
                actualNode->next = l1;
                l1 = l1->next;
            } else {
                actualNode-> next = l2;
                l2 = l2->next;
            }
            actualNode = actualNode->next;
        }
        if (l1 != NULL){
            actualNode-> next = l1;
        } else if (l2 != NULL){
            actualNode-> next = l2;
        }
        return head.next;
    }
};