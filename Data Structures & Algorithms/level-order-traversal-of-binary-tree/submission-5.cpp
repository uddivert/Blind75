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
        if (!root)
        {
            return {};
        }
        vector<vector<int>> list;
        dfs(root, list, 0);
        return list;
    }
    void dfs(TreeNode* root, vector<vector<int>>& list, int index)
    {
        if (!root)
        {
            return;
        }
        else if (list.size() <= index)
        {
            list.push_back({});
        }
        list[index].push_back(root->val);
        dfs(root->left, list, index + 1);
        dfs(root->right, list, index + 1);
    }
};
