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
       ListNode* fast = head;
       ListNode* slow = head; 

       while (fast && fast->next)
       {
        fast = fast->next->next;
        slow = slow->next;
       }

       ListNode* current = slow->next;
       slow->next = nullptr;

       ListNode* reversed = nullptr;
       while (current)
       {
        ListNode* next = current->next;
        current->next = reversed;
        reversed = current;
        current = next;
       }

       ListNode* result = head;
       while (reversed)
       {
        ListNode* next = reversed->next;
        reversed->next = result->next;
        result->next = reversed;
        result = result->next->next;
        reversed = next;
       }
    }
};
