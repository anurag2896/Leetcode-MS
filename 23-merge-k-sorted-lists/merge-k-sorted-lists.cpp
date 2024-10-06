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

class comp {
    public:
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newHead = new ListNode();
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        if(lists.empty())
            return NULL;
        
        for(auto list:lists) {
            if(list)
                pq.push(list);
        }

        ListNode* temp = newHead;
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            temp->next = new ListNode(node->val);
            temp = temp->next;
            node=node->next;

            if(node)
                pq.push(node);
        }

        return newHead->next;
    }
};