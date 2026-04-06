class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> pre_reqs;
        unordered_set<int> visiting;

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
            if (!dfs(i, pre_reqs, visiting))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course, unordered_map<int, vector<int>>& pre_reqs, unordered_set<int>& visiting)
    {
        if (visiting.count(course))
        {
            return false;
        }
        if (pre_reqs[course].empty())
        {
            return true;
        }
        visiting.insert(course);
        for (int pre : pre_reqs[course])
        {
            if (!dfs(pre, pre_reqs, visiting))
            {
                return false;
            }
        }
        visiting.erase(course);
        pre_reqs[course].clear();
        return true;
    }
};
