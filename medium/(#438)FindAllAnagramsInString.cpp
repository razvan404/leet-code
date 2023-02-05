class Solution {
    int hash(char c){
        return c - 'a';
    }
    const static int ocrSize = 26;
public:
    vector<int> findAnagrams(string s, string p) {
        int sSize = s.size(), pSize = p.size();
        if (pSize > sSize) {
            return {};
        }

        vector<int> ocr(ocrSize), window(ocrSize);
        vector<int> ans;
        
        for (const auto& chr : p) {
            ocr[hash(chr)]++;
        }

        int matches = 0;

        for (int i = 0; i < pSize; ++i) {
            window[hash(s[i])]++;
        }

        if (ocr == window) {
            ans.push_back(0);
        }

        int beg = 1, end = pSize;

        while (end < sSize) {
            window[hash(s[beg - 1])]--;
            window[hash(s[end])]++;
            if (ocr == window) {
                ans.push_back(beg);
            }
            beg++, end++;
        }

        return ans;
    }
};