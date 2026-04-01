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
        vector <int> list;

        while (head)
        {
            list.push_back(head->val);
            head = head->next;
        }
        reverse(list.begin(), list.end());

        ListNode* result = new ListNode(0);
        ListNode* current = result;
        for (int i : list)
        {
            current->next = new ListNode(i);
            current = current->next;
        }
        return result->next;
    }
};
