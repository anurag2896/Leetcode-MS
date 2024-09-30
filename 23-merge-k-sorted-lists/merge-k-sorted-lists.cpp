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


class comparator {
public:
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;

        for(auto list:lists) {
            if(list)
                pq.push(list);
        }

        ListNode* newHead = new ListNode();
        ListNode* temp = newHead;


        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            temp->next = top;
            temp = temp->next;

            if(top->next) {
                pq.push(top->next);
            }
        }

        return newHead->next;
    }
};