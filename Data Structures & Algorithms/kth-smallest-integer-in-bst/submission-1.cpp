/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* node = root;
        while (true)
        {
            while (node)
            {
                stack.push(node);
                node = node->left;
            }
            node = stack.top();
            stack.pop();
            k --;
            if (k == 0)
            {
                return node->val;
            }
            else
            {
                node = node->right;
            }
        }
        return -1;
    }
};
