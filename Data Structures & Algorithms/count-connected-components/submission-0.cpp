class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n, false);
        for(const auto & e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int count = 0;
        for (int i = 0; i < adj.size(); i ++)
        {
            if (!visit[i])
            {
                dfs(adj, visit, i);
                count ++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& adj, vector<bool>& visit, int node) 
    {
        visit[node] = true;
        for (int n : adj[node] )
        {
            if (!visit[n])
            {
                dfs(adj, visit, n);
            }
        }
    }
};
