\*
Author: allannozomu
Runtime: 8 ms
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL){
            return NULL;
        }
        
        ListNode* curr_node = head->next, *result_list = head;
        int prev_value = result_list->val;
        
        while(curr_node != NULL){
            if (curr_node->val != prev_value){
                result_list->next = curr_node;
                result_list = result_list->next;
                prev_value = result_list->val;
            }
            curr_node = curr_node->next;
        }
        result_list->next = NULL;
        return head;
    }
};