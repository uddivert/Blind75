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
        unordered_map<Node*, Node*> node_mapper;
        return dfs(node, node_mapper);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& node_mapper)
    {
        if (!node)
        {
            return nullptr;
        }
        else if (node_mapper.count(node))
        {
            return node_mapper[node];
        }
        node_mapper[node] = new Node(node->val);

        for (auto n : node->neighbors)
        {
            node_mapper[node]->neighbors.push_back(dfs(n, node_mapper));
        }
        return node_mapper[node];
    }
};
