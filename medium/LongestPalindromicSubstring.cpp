class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int lenMax = 1, startIndex = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (i != 0 && s[i + 1] == s[i - 1]) {
                int j = 2;
                while (j <= i && j < n - i && s[i - j] == s[i + j]) {
                    j++;
                }
                if (2 * j - 1 > lenMax) {
                    lenMax = 2 * j - 1;
                    startIndex = i - j + 1;
                }
            }
            if (s[i] == s[i + 1]) {
                int j = 1;
                while (j <= i && j < n - i - 1 && s[i - j] == s[i + 1 + j]) {
                    j++;
                }
                if (2 * j > lenMax) {
                    lenMax = 2 * j;
                    startIndex = i - j + 1;
                }
            }
        }
        return s.substr(startIndex, lenMax);
    }
};