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
        ListNode* first=head, *sec=head;
        while(n--) {
            sec=sec->next;
        }
        if(!sec)
            return head->next;
        
        while(sec->next) {
            sec=sec->next;
            first=first->next;
        }
        
        ListNode* temp = first->next;
        // cout<<first->val<<endl;
        first->next = first->next->next;
        // free(temp);
        
        return head;
    }
};