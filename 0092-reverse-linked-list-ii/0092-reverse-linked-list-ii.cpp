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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;

        // Find the left Node from where the link list should be reversed
        ListNode *leftNode = head;
        ListNode *prev = NULL;
        while(--left){
            prev = leftNode;
            leftNode = leftNode->next;
        }

        ListNode *rightNode = head;
        while(--right)
            rightNode = rightNode->next;

        // store all the nodes after right and set its value to null 
        // setting the value to null is necessary for reversal
        ListNode *nextElements = NULL;
        if(rightNode){
            nextElements = rightNode->next;
            rightNode->next = NULL;
        }
        leftNode = reverse(leftNode, NULL, NULL);

        if(prev)
            prev->next = leftNode;
        else
            head = leftNode;

        // now attach all the right nodes after reversal
        rightNode = head;
        while(rightNode->next)
            rightNode = rightNode->next;
        
        rightNode->next = nextElements;

        return head;
    }
};