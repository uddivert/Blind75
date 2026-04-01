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
    ListNode* reverseList(ListNode* head) {

        ListNode * current = head;
        vector <int> list;

        while(current != nullptr)
        {
            list.push_back(current->val);
            current = current->next;
        }

        std::reverse(list.begin(), list.end());

        ListNode dummy;
        ListNode * node = &dummy;
        for (int i : list)
        {
            node ->next = new ListNode(i);
            node = node->next;
        }
        return dummy.next;
        
    }
};
