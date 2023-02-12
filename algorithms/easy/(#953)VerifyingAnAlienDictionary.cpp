class Solution {
public:
    short order[UCHAR_MAX];
    int aliencmp(string& str1, string& str2) {
        for (int i = 0; i < min(str1.size(), str2.size()); ++i) {
            if (order[str1[i]] < order[str2[i]]) {
                return -1;
            }
            else if (order[str1[i]] > order[str2[i]]) {
                return 1;
            }
        }
        if (str1.size() < str2.size()) {
            return -1;
        }
        if (str1.size() > str2.size()) {
            return 1;
        }
        return 0;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); ++i) {
            this->order[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            if (aliencmp(words[i], words[i + 1]) > 0) {
                return false;
            }
        }
        return true;
    }
};