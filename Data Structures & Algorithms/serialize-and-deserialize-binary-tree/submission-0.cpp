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

class Codec {
public:

    // Encodes a tree to a single string.
    void serialize_helper(ostringstream& oss, TreeNode* root)
    {
        if (!root)
        {
            oss << "N,";
            return;
        }
        oss << root->val << ",";
        serialize_helper(oss, root->left);
        serialize_helper(oss, root->right);
    }

    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize_helper(oss, root);
        return oss.str();
    }

    TreeNode* deserialize_helper(istringstream& iss)
    {
        string token;
        getline(iss, token, ',');
        if(token == "N")
        {
            return nullptr;
        }
        TreeNode *node = new TreeNode(stoi(token));
        node->left = deserialize_helper(iss);
        node->right = deserialize_helper(iss);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize_helper(iss);
    }
};
