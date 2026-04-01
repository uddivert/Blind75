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
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            return true;
        }

        stack<tuple<TreeNode*, int, int>> stack;
        stack.push(make_tuple( root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()));

        while (!stack.empty())
        {
            TreeNode* node = std::get<0>(stack.top());
            int min = std::get<1>(stack.top());
            int max = std::get<2>(stack.top());
            stack.pop();

            if (!(node-> val > min && node->val < max))
            {
                return false;
            }
            if (node->left)
            {
                stack.push(make_tuple(node->left, min, node->val));
            }
            if (node->right && node->right )
            {
                stack.push(make_tuple(node->right, node->val, max));
            }
        }
        return true;
    }
};
