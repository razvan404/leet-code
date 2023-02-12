class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maximum = 0;
        for (int i = 0; i < s.size(); ++i) {
            int freq[UCHAR_MAX]{};
            int j = i;
            while (j < s.size()) {
                if (freq[s[j]]) {
                    break;
                }
                freq[s[j]] = j + 1;
                j++;
            }

            if (j - i > maximum) {
                maximum = j - i;
            }

            if (j < s.size()) {
                i = freq[s[j]] - 1;
            }
            else {
                break;
            }
        }
        return maximum;
    }
};