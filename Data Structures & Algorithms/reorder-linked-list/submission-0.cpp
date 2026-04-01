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
       ListNode* turtle = head;
       ListNode* hare = head; 

       while (hare && hare->next)
       {
        hare = hare->next->next;
        turtle = turtle->next;
       }

       // Reverse middle to end
       ListNode* reversed = turtle;
       ListNode* prev = nullptr;

       while (reversed)
       {
        ListNode* next = reversed->next;
        reversed->next = prev;
        prev = reversed;
        reversed = next;
       }

       // Merge reversed with first half
       reversed = prev;
       ListNode* first = head;
       while (reversed)  // FIX: Just check if second half exists
       {
        ListNode* tmp1 = first->next;
        ListNode* tmp2 = reversed->next;
        first->next = reversed;
        reversed->next = tmp1;
        first = tmp1;
        reversed = tmp2;
       }
       if (first)
        first->next = nullptr;  // FIX: Terminate the list
    }
};
