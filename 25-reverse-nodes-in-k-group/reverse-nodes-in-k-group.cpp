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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int tempK = k;
        ListNode* curr=head, *ahead=head, *prev=NULL;

        ListNode* temp = head;
        while(tempK) {
            if(!temp)
                return head;

            temp = temp->next;
            tempK--;
        }

        tempK = k;
        while(tempK) {
            tempK--;
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }

        head->next = reverseKGroup(temp, k);

        return prev;
    }
};