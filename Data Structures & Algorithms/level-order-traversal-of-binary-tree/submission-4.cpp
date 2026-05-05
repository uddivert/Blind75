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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
    void dfs(TreeNode* root, int level, vector<vector<int>>& traversal)
    {
        if (!root)
        {
            return;
        }
        if (level == traversal.size())
        {
            traversal.push_back(vector<int>());
        }
        traversal[level].push_back(root->val);
        dfs(root->left, level + 1, traversal);
        dfs(root->right, level + 1, traversal);
    }
};
