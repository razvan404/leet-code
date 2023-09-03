class Solution {
private:
    int backtracking(string& s, vector<string>& dictionary, int sPos, vector<int>& cache) {
        if (sPos == s.size()) {
            return 0;
        }
        if (cache[sPos] != -1) {
            return cache[sPos];
        }
        cache[sPos] = 1 + backtracking(s, dictionary, sPos + 1, cache);
        for (const auto& word : dictionary) {
            if (s.compare(sPos, word.size(), word) == 0) {
                cache[sPos] = min(cache[sPos], backtracking(s, dictionary, sPos + word.size(), cache));
            }
        }
        return cache[sPos];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> cache(s.size(), -1);
        return backtracking(s, dictionary, 0, cache);
    }
};
