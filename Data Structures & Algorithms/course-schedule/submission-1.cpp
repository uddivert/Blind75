class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> pre_reqs;
        unordered_set<int> visited;

        for(int i = 0; i < numCourses; i ++)
        {
            pre_reqs[i] = {};
        }
        for (const auto& p : prerequisites)
        {
            pre_reqs[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, pre_reqs, visited))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course, unordered_map<int, vector<int>>& pre_reqs, unordered_set<int>& visited)
    {
        if (visited.count(course))
        {
            return false;
        }
        if (pre_reqs[course].empty())
        {
            return true;
        }
        visited.insert(course);
        for (int pre : pre_reqs[course])
        {
            if (!dfs(pre, pre_reqs, visited))
            {
                return false;
            }
        }
        visited.erase(course);
        pre_reqs[course].clear();
        return true;
    }
};
