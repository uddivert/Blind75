class Solution {
   public:
    int numDecodings(string s) {
        unordered_map<int, int> cache;
        return dfs(s, cache, 0);
    }
    int dfs(string s, unordered_map<int, int>& cache, int index) {
        if (index == s.length()) {
            return 1;
        }
        if (cache.count(index)) {
            return cache[index];
        }
        if (s[index] == '0') {
            return 0;
        }
        int result = dfs(s, cache, index + 1);
        if (index + 1 < s.size() && (s[index] == '1' || s[index] == '2'&& s[index + 1] < '7')) {
            result += dfs(s, cache, index + 2);
        }
        return cache[index] = result;
    }
};
