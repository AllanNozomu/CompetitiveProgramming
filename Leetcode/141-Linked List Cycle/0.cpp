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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> appeared;
        while(head != NULL){
            if (appeared.find(head) != appeared.end()) return true;
            appeared.insert(head);
            head = head->next;
        }
        return false;
    }
};