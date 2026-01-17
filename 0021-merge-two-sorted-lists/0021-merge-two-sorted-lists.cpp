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
    // Brute Force O(n^2)
    void merge(ListNode*& merged, int val){
        if(!merged){
            merged = new ListNode(val);
            return;
        }
        ListNode* temp = merged;
        while(temp->next)
            temp = temp->next;
        temp->next = new ListNode(val);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;

        if(!list1) return list2;
        if(!list2) return list1;

        ListNode *mergedList = NULL;

        ListNode *first = list1, *second = list2;
        while(first && second){
            if(first->val<second->val){
                merge(mergedList, first->val);
                first = first->next;
            }
            else{
                merge(mergedList, second->val);
                second = second->next;
            }
        }

        while(first){
            merge(mergedList, first->val);
            first = first->next;
        }
        while(second){
            merge(mergedList, second->val);
            second = second->next;
        }

        return mergedList;
    }
};