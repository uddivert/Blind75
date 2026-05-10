class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i ++)
        {
            adj[i] = {};
        }
        for (const auto & e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int> visit;
        return dfs(adj, 0, -1, visit) && visit.size() == n;
    }

    bool dfs(unordered_map<int, vector<int>> & adj, int index, int parent, unordered_set<int>& visit)
    {
        if (visit.contains(index))
        {
            return false;
        }
        visit.insert(index);

        for (int i : adj[index])
        {
            if (i == parent)
            {
                continue;
            }
            if (!dfs(adj, i, index, visit))
            {
                return false;
            }
        }
        return true;
    }
};
