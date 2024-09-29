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
        ListNode* tort = head, *hare=head;
        
        while(hare && hare->next) {
            tort = tort->next;
            hare = hare->next->next;

            if(tort==hare)
                return true;
        }
        return false;
    }
};