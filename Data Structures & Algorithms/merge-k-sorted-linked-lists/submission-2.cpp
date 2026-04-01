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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* result = nullptr;
        for (int i = 0; i < lists.size(); i ++)
        {
           result = mergeLists(lists[i], result);
        }
        return result;
    }
private:
    ListNode* mergeLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* result = dummy;
        
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {                
                dummy->next = list1;
                dummy = list1;
                list1 = list1->next;
            }
            else 
            {
                dummy->next = list2;
                dummy = list2;
                list2 = list2->next;
            }
        }
        
        if (!list1)
        {
            dummy->next = list2;
        }
        else if (!list2)
        {
            dummy->next = list1;
        }
        return result->next;
    }
};
