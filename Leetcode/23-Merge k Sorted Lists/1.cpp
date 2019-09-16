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
    ListNode* merge2Lists(ListNode* listA, ListNode* listB){
        ListNode *head = NULL;
        if (listA == NULL){
            return listB;
        }
        if (listB == NULL){
            return listA;
        }
        
        if (listA->val < listB->val){
            head = listA;
            listA = listA->next;
        } else {
            head = listB;
            listB = listB->next;
        }
        
        ListNode *currNode = head;
        while(listA != NULL && listB != NULL){
            if (listA->val < listB->val){
                currNode->next = listA;
                listA = listA->next;
            } else {
                currNode->next = listB;
                listB = listB->next;
            }
            currNode = currNode->next;
        }
        if (listA == NULL){
            currNode->next = listB;
        } else {
            currNode->next = listA;
        }
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        for (auto listNode : lists){
            result = merge2Lists(result, listNode);
        }
        return result;
    }
};