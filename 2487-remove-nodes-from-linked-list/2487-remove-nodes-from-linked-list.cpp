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
/*
First, reverse the linked list. Then traverse the reversed list from the first node (which was originally the last node), maintaining a variable maxVal to track the maximum value seen so far.Update maxVal whenever the current node’s value is greater than it. For each subsequent node, if its value is less than maxVal, remove it using prev and curr pointers; otherwise, keep it and update maxVal. Finally reverse the list again and return it.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *fut = NULL;
        while(curr){
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        int maxVal = head->val;
        ListNode *prev = head;
        ListNode *curr = head->next;

        while(curr){
            if(curr->val<maxVal){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                maxVal = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }

        return reverseList(head);
    }
};