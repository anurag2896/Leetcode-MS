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
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL, *curr=head, *ahead=head;
        while(curr) {
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* prevMid = getMiddle(head);
        ListNode* sec_half = reverse(prevMid->next);
        prevMid->next = NULL;

        ListNode* first_half = head;
        ListNode* temp = new ListNode();
        while(first_half || sec_half) {
            temp->next = first_half;
            first_half = first_half->next;
            temp = temp->next;

            if(sec_half) {
                temp->next = sec_half;
                sec_half = sec_half->next;
                temp = temp->next;
            }
        }
        head = temp->next;

    }
};