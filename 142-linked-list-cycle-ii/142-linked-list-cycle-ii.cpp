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
    ListNode *detectCycle(ListNode *head) {
        ListNode* tort=head, *hare=head;
        do {
            if(!hare || !hare->next)
                return NULL;
            tort=tort->next;
            hare=hare->next->next;
            
        } while(hare!=tort);
        hare=head;
        while(tort!=hare) {
            tort=tort->next;
            hare=hare->next;
        }
        return hare;
    }
};