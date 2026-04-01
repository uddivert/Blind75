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
     queue<TreeNode *> queue;
     queue.push(root);   

     vector<vector<int>> result;
     while (!queue.empty())
     {
        if (!queue.front())
        {
            break;
        }
        int size = queue.size();
        vector<int> temp;
        for (int i = 0; i < size; i ++)
        {
            TreeNode * node = queue.front();
            int val = node->val;
            temp.push_back(val);
            if (node->left)
            {
                queue.push(node->left);
            }
            if (node->right)
            {
                queue.push(node->right);
            }
            queue.pop();
        }
        result.push_back(temp);
     }
     return result;
    }
};
