class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        ListNode* result = lists[0];
        
        // Merge lists[1], lists[2], ... into result
        for (int i = 1; i < lists.size(); i++) {
            result = mergeLists(result, lists[i]);
        }
        
        return result;
    }
    
private:
    ListNode* mergeLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        // Attach remaining nodes
        curr->next = list1 ? list1 : list2;
        
        return dummy->next;
    }
};