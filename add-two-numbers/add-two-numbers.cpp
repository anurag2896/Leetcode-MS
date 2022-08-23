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
        int val1=0, val2=0, sum=0, carry=0;
        ListNode* newHead = new ListNode(), *temp;
        temp=newHead;
        
        while(l1 || l2 || carry) {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
            sum=val1+val2+carry;
            temp->val = sum%10;
            carry=sum/10;
            if(!l1 && !l2 && carry==0)
                temp->next=NULL;
            else 
                temp->next = new ListNode();
            temp=temp->next;
            
        }
        
        return newHead;
    }
};