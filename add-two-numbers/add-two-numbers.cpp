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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(), *temp;
        
        int carry=0, val1, val2, sum;
        
        temp=newHead;
        while(l1 || l2 || carry) {
            if(l1) {
                val1 = l1->val;
                l1=l1->next;
            } else
                val1 = 0;
            
            if(l2) {
                val2 = l2->val;
                l2=l2->next;
            } else
                val2 = 0;
            
            sum=val1+val2+carry;
            carry = sum/10;
            sum%=10;
            
            temp->next = new ListNode(sum);
            temp=temp->next;
        }
        
        return newHead->next;
        
    }
};