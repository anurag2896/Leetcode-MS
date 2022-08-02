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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(), *temp;
        temp=newHead;
        
        while(l1 && l2) {
            if(l1->val<l2->val) {
                newHead->next = l1;
                l1=l1->next;
            }
            else {
                newHead->next = l2;
                l2=l2->next;
            }
            newHead = newHead->next;
        }
        
        if(l1)
            newHead->next = l1;
        else if(l2)
            newHead->next = l2;
        
        return temp->next;
    }
};