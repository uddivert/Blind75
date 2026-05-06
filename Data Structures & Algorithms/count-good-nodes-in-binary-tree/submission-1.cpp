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
    int goodNodes(TreeNode* root) { 
        int count = 0;
        int greatest = numeric_limits<int>::min();
        dfs(root, greatest, count);
        return count;
    }
    void dfs(TreeNode* root, int greatest, int &count)
    {
        if (!root)
        {
            return;
        }
        if (root->val >= greatest)
        {
            count ++;
        }
        greatest = max(root->val, greatest);
        dfs(root->left, greatest, count);
        dfs(root->right, greatest, count);
    } 
};
