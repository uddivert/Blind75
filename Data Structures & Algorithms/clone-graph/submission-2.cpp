/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }
    Node* dfs(Node* node, std::unordered_map<Node*, Node*>& map)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (map.count(node))
        {
            return map[node];
        }
        Node * new_node = new Node(node->val);
        map[node] = new_node;
        for (const auto & n : node-> neighbors)
        {
            new_node->neighbors.push_back(dfs(n, map));
        }
        return new_node;
    }
};
