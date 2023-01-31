class Solution {
public:
    string commonPrefix(string& str1, string &str2) {
        string s;

        for (int i = 0; i < min(str1.size(), str2.size()); i++) {
            if (str1[i] != str2[i]) {
                break;
            }
            s.push_back(str1[i]);
        }

        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        if (strs.size() == 1) {
            return strs[0];
        }
        string common = commonPrefix(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); i++) {
            common = commonPrefix(common, strs[i]);
        }
        if (common == "") {
            return "";
        }
        return common;
    }
};