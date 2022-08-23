/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node* temp=head, *hare, *newHead;
        while(temp) {
            hare=temp->next;
            temp->next = new Node(temp->val);
            if(temp->next)
                temp->next->next=hare;
            temp=hare;
        }
        temp=head;
        
        while(temp && temp->next) {
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp=temp->next->next;
        }
        
        temp=head->next, newHead=head->next;
        while(temp) {
            head->next=temp->next;
            head=head->next;
            temp->next = temp->next ? temp->next->next : NULL;
            temp=temp->next;
        }
        
        return newHead;
    }
};