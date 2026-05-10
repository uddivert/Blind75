class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
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

        unordered_set<int> visited;
        int count = 0;
        for (int i = 0; i < n; i ++)
        {
            if (!visited.contains(i))
            {
                dfs(adj, visited, i);
                count ++;
            }
        }
        return count;
    }

    void dfs(unordered_map<int, vector<int>> adj, unordered_set<int> &visited, int index)
    {
        if (visited.contains(index)) 
        {
            return;
        }
        visited.insert(index);
        for (int i : adj[index])
        {
            dfs(adj, visited, i);
        }
    }
};
