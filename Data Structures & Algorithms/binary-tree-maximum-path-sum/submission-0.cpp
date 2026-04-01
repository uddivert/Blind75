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
    int result = std::numeric_limits<int>::min();
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int left_max = max(dfs(root->left), 0);
        int right_max = max(dfs(root->right), 0);

        result = max(result, (root->val + left_max + right_max));
        return root->val + max(left_max, right_max); 
    }
};
