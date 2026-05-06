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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result; 
    }
    void dfs(TreeNode* root, int index, vector<int>& vals)
    {
        if (!root)
        {
            return;
        }
        if (vals.size() == index)
        {
            vals.push_back(root->val);
        }
        dfs(root->right, index + 1, vals);
        dfs(root->left, index + 1, vals);
    }
};
