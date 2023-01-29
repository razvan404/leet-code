class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans = "";

        if (numRows == 1) {
            return s;
        }

        for (int i = 0; i < n; i += 2 * (numRows - 1)) {
            ans += s[i];
        }

        for (int j = 1; j < numRows - 1; ++j) {
            for (int i = j; i < n;) {
                ans += s[i];
                if ((i - j) % (numRows * 2 - 2) == 0) {
                    i += 2 * (numRows - j - 1);
                }
                else {
                    i += 2 * j;
                }
            }
        }

        for (int i = numRows - 1; i < n; i += 2 * (numRows - 1)) {
            ans += s[i];
        }

        return ans;
    }
};