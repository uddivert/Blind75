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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> p_stack;
        std::stack<TreeNode*> q_stack;
        p_stack.push(p);
        q_stack.push(q);

        while (!p_stack.empty() && !q_stack.empty())
        {
            TreeNode* p_node = p_stack.top();
            TreeNode* q_node = q_stack.top();
            p_stack.pop();
            q_stack.pop();
            if (!p_node && !q_node)
            {
                continue;
            }
            if (!p_node || !q_node)
            {
                return false;
            }
            if (p_node->val != q_node->val)
            {
                return false;
            }
            if (p_node)
            {
                p_stack.push(p_node->left);
                p_stack.push(p_node->right);
            }
            if (q_node)
            {
                q_stack.push(q_node->left);
                q_stack.push(q_node->right);
            }
        }
        return p_stack == q_stack;
    }
};
