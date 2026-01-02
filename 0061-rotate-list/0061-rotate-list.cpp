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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL)
            return head;

        int count = 0;
        ListNode *temp = head;
        while(temp){
            count++;
            temp=temp->next;
        }
        k = k % count; // set k < count if its greater
        
        if(k==0) return head;

        count -= k; // total no of steps to move
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(count--){
            prev = curr;
            curr = curr->next;
        }

        // Make prev = last Node
        prev->next = NULL;

        temp = curr;
        while(temp->next)
            temp = temp->next;
        
        temp->next = head;
        head = curr;
        return head;

    }
};