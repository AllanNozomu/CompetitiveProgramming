\*
Author: allannozomu
Runtime: 32 ms
Memory: 11.4 MB*\

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> nodes_queue;
        ListNode* new_head = NULL, *previous_node;
        
        for (ListNode* head : lists){
            if (head != NULL)
                nodes_queue.push({-head->val, head});
        }
        
        while(!nodes_queue.empty()){
            ListNode* currNode = nodes_queue.top().second;
            nodes_queue.pop();
            
            if (new_head == NULL){
                new_head = currNode;
            } else{
                previous_node->next = currNode;
            }
            if (currNode->next != NULL){
                nodes_queue.push({-currNode->next->val, currNode->next});
            }
            previous_node = currNode;
        }
        
        return new_head;
    }
};