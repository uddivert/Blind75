class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> map;
        for (auto v : prerequisites)
        {
            map[v[0]].push_back(v[1]);
        }
        unordered_set<int> seen;
        for (int i = 0; i < numCourses; i ++)
        {
            if (!dfs(i,seen, map))
            {
                return false;
            }
        }
        return true;
    }
    bool dfs(int course, unordered_set<int>& seen, unordered_map<int,vector<int>>& map)
    {
        if (seen.count(course))
        {
            return false;
        }
        if (map[course].empty())
        {
            return true;
        }
        seen.insert(course);
        for (int i : map[course])
        {
            if (!dfs(i,seen, map))
            {
                return false;
            }

        }
        seen.erase(course);
        map[course].clear();
        return true;

    }
};
