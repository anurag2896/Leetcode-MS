/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head;
        
        while(n--) {
            ahead = ahead->next;
        }

        if(!ahead)
            return head->next;

        ListNode* prev_target = head;
        while(ahead && ahead->next) {
            prev_target = prev_target->next;
            ahead = ahead->next;
        }

        ListNode* target = prev_target->next;
        prev_target->next = prev_target->next ? prev_target->next->next : NULL;

        delete(target);
        return head;
    }
};