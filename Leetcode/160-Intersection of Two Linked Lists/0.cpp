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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> appeared;
        
        while(headA != NULL){
            appeared.insert(headA);
            headA = headA->next;
        }
        while(headB != NULL){
            auto target = appeared.find(headB);
            if (target != appeared.end()){
                return *target;
            }
            headB = headB->next;
        }
        return NULL;
    }
};