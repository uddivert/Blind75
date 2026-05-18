class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> cache;
        return dfs(s, 0, wordDict, cache);
    }
    bool dfs(string s, int index, vector<string>& wordDict, unordered_map<int, bool>& cache) {
        if (index == s.length()) {
            return true;
        }
        if (cache.contains(index)) {
            return cache[index];
        }
        for (string word : wordDict) {
            if (index + word.size() <= s.size() && s.substr(index, word.size()) == word) {
                if (dfs(s, index + word.size(), wordDict, cache)) {
                    cache[index] = true;
                    return true;
                }
            }
        }
        return cache[index] = false;
    }
};
