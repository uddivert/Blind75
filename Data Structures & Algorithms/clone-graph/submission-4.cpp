
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map; // old, new
        return dfs(map, node);
    }
    Node* dfs(unordered_map<Node*, Node*>& map, Node* node) {
        if (!node)
        {
            return nullptr;
        }    
        if (map.contains(node))
        {
            return map[node];
        }
        Node * newNode = new Node(node->val);
        map[node] = newNode;
        for (auto n : node->neighbors)
        {
            newNode->neighbors.push_back(dfs(map, n));
        }
        return newNode;
    }
};
