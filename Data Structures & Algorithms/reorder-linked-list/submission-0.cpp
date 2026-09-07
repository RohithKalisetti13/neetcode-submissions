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
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;
        ListNode* slow = head;
        ListNode* fast = head;

        //finding middle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //splitting
        ListNode* curr = slow->next;
        slow->next = nullptr;

        //reversing
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        //merging
        ListNode* first = head;
        ListNode* second = prev;


        while(second){
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
