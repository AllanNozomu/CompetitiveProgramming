\*
Author: allannozomu
Runtime: 4 ms
Memory: N/A*\

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL){
            return head;
        }
        
        ListNode* current_node = head->next, * prev_node = head;
        head->next = NULL;
        while(current_node != NULL){
            ListNode* next_aux = current_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_aux;
        }
        
        return prev_node;
    }
};