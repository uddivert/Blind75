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
    int diameterOfBinaryTree(TreeNode* root) {
        int s = 0;
        dfs(root, s);
        return s; 
    }
    int dfs(TreeNode* root, int& s)
    {
        if (!root)
        {
            return 0;
        }
        int one = dfs(root->right, s);
        int two = dfs(root->left, s);
        s = max(s, one + two);
        return 1 + max(one, two);
    }
};
