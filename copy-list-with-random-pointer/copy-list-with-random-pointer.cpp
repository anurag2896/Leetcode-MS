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
        Node* newHead, *temp=head;
        while(temp) {
            Node* curr = new Node(temp->val);
            curr->next=temp->next;
            temp->next=curr;
            temp=temp->next->next;
        }
        
        temp=head;
        while(temp && temp->next) {
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp=temp->next->next;
        }
        
        newHead = head->next;
        temp = newHead;
        while(head) {
            head->next = head->next->next;
            head=head->next;
            
            
            temp->next = temp->next ? temp->next->next : NULL;
            temp=temp->next;
        }
        
        return newHead;
    }
};