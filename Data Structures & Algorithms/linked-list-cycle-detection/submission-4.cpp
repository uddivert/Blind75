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
    bool hasCycle(ListNode* head) {
       ListNode* hare = head;

       while (hare && hare->next)
       {
        head = head ->next;
        hare = hare->next->next;
        if (head == hare)
        {
            return true;
        }
       } 
       return false;
    }
};
