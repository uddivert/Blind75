class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0)
        {
            return true;
        }
        vector<vector<int>> adj(n);
        for (const auto& e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited;
        if (!dfs(0, -1, visited, adj))
        {
            return false;
        }
        return visited.size() == n;
    }

    bool dfs(int node, int parent, unordered_set<int>& visited, const vector<vector<int>>& adj)
    {
        if (visited.count(node))
        {
            return false;
        }
        visited.insert(node);
        for (int edge : adj[node])
        {
            if (edge == parent)
            {
                continue;
            }
            if (!dfs(edge, node, visited, adj))
            {
                return false;
            }
        }
        return true;
    }
};
