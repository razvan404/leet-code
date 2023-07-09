class Solution {
public:
    int largestVariance(string s) {
        int maxVariance = 0;
        unordered_set<char> distinctChars(begin(s), end(s));
        for (const char& a : distinctChars) {
            for (const char& b : distinctChars) {
                if (a == b) {
                    continue;
                }
                bool hasB = false, firstB = false;
                int var = 0;
                for (const char& chr : s) {
                    if (chr == a) {
                        var += 1;
                    } else if (chr == b) {
                        hasB = true;
                        if (firstB && var >= 0) {
                            firstB = false;
                        } else {
                            --var;
                            if (var < 0) {
                                firstB = true;
                                var = -1;
                            }
                        }
                    }
                    if (hasB) {
                        maxVariance = max(maxVariance, var);
                    }
                }
            }
        }
        return maxVariance;
    }
};