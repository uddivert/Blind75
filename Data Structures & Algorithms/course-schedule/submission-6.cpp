class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // The pair [0, 1], indicates that must take course 1 before taking course 0
        unordered_map <int, vector<int>> adj;
        for (auto pre : prerequisites)
        for(int i = 0; i < prerequisites.size(); i ++)
        {
            adj[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> seen;
        for (int i = 0; i < numCourses; i ++)
        {
            if (!dfs(i, adj, seen))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(int index, unordered_map<int, vector<int>>& adj, unordered_set<int>& seen)
    {
        if (seen.contains(index))
        {
            return false;
        }
        if (adj[index].empty())
        {
            return true;
        }
        seen.insert(index);
        for (int i : adj[index])
        {
            if(!dfs(i, adj, seen))
            {
                return false;
            }
        }
        seen.erase(index);
        adj[index].clear();
        return true;
    }
};
