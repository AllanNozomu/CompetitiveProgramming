\*
Author: allannozomu
Runtime: 28 ms
Memory: 12.6 MB*\

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
    bool isPalindrome(ListNode* head) {
        int length = 0;
        
        ListNode* head_backup = head;
        
        while(head != NULL){
            length++;
            head = head->next;
        }
        
        if (length == 0 || length == 1){
            return true;
        }
        
        head = head_backup;
        
        ListNode* curr = head, *prev = NULL;
        int counter = 0;
        while(counter < length / 2){
            
            cout << head->val << endl;
            
            head = head->next;
            counter++;
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        curr = prev;
        if (length % 2) head = head->next;
        while(head != NULL){
            cout << curr->val << " " << head->val << endl;
            if (curr->val != head->val) return false;
            head = head->next;
            curr = curr->next;
        }
        return true;
        
    }
};