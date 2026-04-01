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
        vector<int> temp;
        ListNode *current = head;
        while (current != nullptr)
        {
            temp.push_back(current->val);
            current = current -> next;
        }
        std::reverse(temp.begin(), temp.end());

        ListNode *my_head = new ListNode(0);
        ListNode* node = my_head;

        for (int i = 0; i < temp.size(); i ++)
        {
            node->next = new ListNode(temp[i]);
            node = node -> next; 
        }
        return my_head->next;
    }
};
