/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> seen;
        ListNode *temp = headA;
        while(temp){
            seen[temp] = true;
            temp = temp->next;
        }

        temp = headB;
        while(temp){
            if(seen[temp])
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
};