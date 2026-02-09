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
    void cloneLL(Node*& head, Node*& clone, Node*& tail){
        Node* temp = head;
        while(temp){
            if(!clone){
                clone = tail = new Node(temp->val);
            } else {
                tail->next = new Node(temp->val);
                tail = tail->next;
            }
            temp = temp->next;
        }
    }
    // Brute Force - O(n^2) time
    Node* copyRandomList(Node* head) {
        // Handle empty list
        if(!head) return NULL;
        // Handle single-node list
        if(!head->next){
            Node *clone = new Node(head->val);
            // If random points to itself, clone should also point to itself
            if(head->random)
                clone->random = clone;
            return clone;
        }
        
        // Step 1: Create a cloned ll with only 'next' pointers
        Node *clone = NULL;
        Node *tail = NULL;
        cloneLL(head, clone, tail);
        
        Node *original = head;
        Node *copy = clone;
        // Step 2: Set random pointers in the cloned list
        while(original && copy){
            if(original->random){
                // Count steps to reach the random node in original ll
                Node *target = original->random;
                int steps = 0;
                Node *curr = head;
                while(curr!=target){
                    steps++;
                    curr = curr->next;
                }
                // Move the same number of steps in cloned list
                Node* cloneRandom = clone;
                while(steps--)
                    cloneRandom = cloneRandom->next;
                // Assign the random pointer
                copy->random = cloneRandom;
            }
            original = original->next;
            copy = copy->next;
        }
        
        return clone;
    }
};