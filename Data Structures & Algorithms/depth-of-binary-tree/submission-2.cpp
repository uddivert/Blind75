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
    int maxDepth(TreeNode* root) {
        std::stack<pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int height = 0;
        while (!stack.empty())
        {
            int current_height = stack.top().second;
            TreeNode* node = stack.top().first;
            stack.pop();

            if (node)
            {
                height = max(height, current_height);
                stack.push({node->left, current_height + 1});
                stack.push({node->right, current_height + 1});
            }
        }
        return height;
    }
};
