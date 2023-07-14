class Solution {
    int hash(char c) {
        return c - 'a';
    }
    const static int ocrSize = 26;
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) {
            return false;
        }
        vector<int> ocr(ocrSize), window(ocrSize);
        for (const auto& chr : s1) {
            ocr[hash(chr)]++;
        }

        for (int i = 0; i < n1; ++i) {
            window[hash(s2[i])]++;
        }

        if (ocr == window) {
            return true;
        }

        int beg = 1, end = n1;
        while (end < n2) {
            window[hash(s2[beg - 1])]--;
            window[hash(s2[end])]++;
            if (ocr == window) {
                return true;
            }
            beg++, end++;
        }
        return false;
    }
};