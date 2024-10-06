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
        int u=0, v=0, carry=0;

        ListNode* newHead = new ListNode(), *temp;
        temp = newHead;

        while(l1 || l2 || carry) {
            u = l1 ? l1->val : 0;
            v = l2 ? l2->val : 0;

            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;

            int sum = u+v+carry;
            carry = sum/10;
            sum%=10;

            temp->next = new ListNode(sum);
            temp = temp->next;
        }

        return newHead->next;
    }
};