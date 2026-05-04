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
        if (!head)
        {
            return false;
        } 
        ListNode* second = head;
        while(second && second->next)
        {
            second = second->next->next;
            head = head->next;
            if (head == second)
            {
                return true;
            }
        }
        return false;
    }
};
