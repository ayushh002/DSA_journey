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
        if(!head || k==1) return head;
        ListNode* first = new ListNode();
        first->next = head;
        head = first;
        while(true){
            ListNode* check = first;
            for (int i = 0; i < k && check; i++) {
                check = check->next;
            }
            if (!check) break;   // not enough nodes
            
            int x = k;
            ListNode* second = first->next;
            ListNode* prev = first;
            ListNode* curr = first->next;
            while(x-- && curr){
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }
            first->next = prev;
            second->next = curr;
            first = second;
        }
        
        ListNode* del = head;
        head = head->next;
        delete del;
        return head;
    }
};