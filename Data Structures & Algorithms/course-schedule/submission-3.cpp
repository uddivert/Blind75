class Solution {
public:
    unordered_set<int> visiting;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj_map;
        for (int i = 0; i < numCourses; i ++)
        {
            adj_map[i] = {};
        } 
        for (const auto& pre: prerequisites)
        {
            adj_map[pre[0]].push_back(pre[1]);
        }
        for (int i = 0; i < numCourses; i ++)
        {
            if (!dfs(i, prerequisites, adj_map))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(int course, vector<vector<int>>& prerequisites, unordered_map<int, vector<int>>& adj_map)
    {
        if (visiting.contains(course))
        {
            return false;
        }
        if (adj_map[course].empty())
        {
            return true;
        }
        visiting.insert(course);
        for (int i : adj_map[course])
        {
            if(!dfs(i, prerequisites, adj_map))
            {
                return false;
            }
        }
        visiting.erase(course);
        adj_map[course].clear();
        return true;
    }
};
