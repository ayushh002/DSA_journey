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
    // Basic method: O(n+m) time and space as we are creating node uptil (n+m).
    void merge(ListNode*& head, ListNode*& tail, int val){
        if(!head){
            head = tail = new ListNode(val);
            return;
        }
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;

        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *head = NULL, *tail = NULL;

        ListNode *first = list1, *second = list2;
        while(first && second){
            if(first->val<second->val){
                merge(head, tail, first->val);
                first = first->next;
            }
            else{
                merge(head, tail, second->val);
                second = second->next;
            }
        }

        // Add remaining nodes
        tail->next = first ? first : second;

        return head;
    }
};