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
    
    ListNode* merge_list(ListNode* listA, ListNode* listB){
        if (listA == NULL){
            return listB;
        }
        if (listB == NULL){
            return listA;
        }
        ListNode* head = listA;
        while(listA->next != NULL){
            listA = listA ->next;
        }
        listA->next = listB;
        return head;
    }
    
    ListNode* reverse_list(ListNode* curr){
        ListNode* prev = NULL, *next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr_node = head;
        ListNode* result_list = NULL;
        
        while(curr_node != NULL){
            ListNode* sub_list_head = curr_node;
            int node_count = 1;
        
            while(node_count < k && curr_node != NULL){
                node_count++;
                curr_node = curr_node -> next;
            }
            if (curr_node == NULL){
                return merge_list(result_list, sub_list_head);
            }
            ListNode* sub_list_tail = curr_node;
            curr_node = curr_node -> next;
            sub_list_tail->next = NULL;
            
            sub_list_head = reverse_list(sub_list_head);
            result_list = merge_list(result_list, sub_list_head);
        }
        
        return result_list;
    }
};