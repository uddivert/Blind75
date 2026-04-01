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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> root_stack;
        root_stack.push(root);
        while (!root_stack.empty())
        {
           TreeNode* node = root_stack.top();
           root_stack.pop(); 
           if (!node)
           {
            continue;
           }
           if (node->val == subRoot->val && same_root(node, subRoot))
           {
            return true;
           }
           root_stack.push(node->left);
           root_stack.push(node->right);
        }
        return false;
    }
    bool same_root(TreeNode* root, TreeNode*subRoot)
    {
        stack<TreeNode*> root_stack;
        root_stack.push(root);

        stack<TreeNode*> sub_stack;
        sub_stack.push(subRoot);
        while (!root_stack.empty() && !sub_stack.empty())
        {
            TreeNode* root = root_stack.top();
            TreeNode* sub = sub_stack.top();
            sub_stack.pop();
            root_stack.pop();
            if (!root&& !sub)
            {
                continue;
            }
            if (!root || !sub)
            {
                return false;
            }
            if (root->val != sub-> val)
            {
                return false;
            }
            root_stack.push(root->left);
            root_stack.push(root->right);
            sub_stack.push(sub->left);
            sub_stack.push(sub->right);
        }
        return true;
    }
};
