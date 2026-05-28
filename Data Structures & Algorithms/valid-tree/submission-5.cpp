class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((n < edges.size()))
        {
            return false;
        }
        unordered_map<int, vector<int>> adj;
        for (auto v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        unordered_set<int> seen;
        if (!dfs(0, adj, seen, -1))
        {
            return false;
        }
        return seen.size() == n;
    }
    bool dfs(int node, unordered_map<int, vector<int>>& adj, unordered_set<int>& seen, int parent)
    {
        if (seen.count(node))
        {
            return false;
        }
        seen.insert(node);
        for (int i : adj[node])
        {
            if (i == parent)
            {
                continue;
            }
            else
            {
                if (!dfs(i, adj, seen, node))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
