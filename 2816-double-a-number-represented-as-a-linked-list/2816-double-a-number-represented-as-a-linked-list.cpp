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
    ListNode* reverse(ListNode*& curr, ListNode* prev, ListNode* fut){
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head, NULL, NULL);
        ListNode *newHead = new ListNode();
        ListNode *tail = newHead;
        ListNode *temp = head;
        int carry = 0;
        while(temp || carry){
            int sum = carry;
            if(temp){
                sum += 2*(temp->val);
                temp = temp->next;
            }
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            tail = tail->next;
        }

        ListNode *del = newHead;
        newHead = newHead->next;
        delete del;
        newHead = reverse(newHead, NULL, NULL);
        return newHead;
    }
};