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
    ListNode* reverse(ListNode* head) {
        ListNode* curr=head, *prev=NULL, *ahead;
        while(curr) {
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* tort=head, *hare=head;
        while(hare && hare->next && hare->next->next) {
            hare=hare->next->next;
            tort=tort->next;
        }
        tort->next = reverse(tort->next);
        tort=tort->next;
        while(tort) {
            if(head->val!=tort->val)
                return false;
            head=head->next;
            tort=tort->next;
        }
        return true;
    }
};