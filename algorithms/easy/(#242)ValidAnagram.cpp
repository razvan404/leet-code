class Solution {
public:
    bool isAnagram(string& s, string& t) {
        uint16_t ocr[26]{};
        if (s.size() != t.size()) {
            return false;
        }
        for (auto& chr : s) {
            ocr[chr - 'a']++;
        }
        for (auto& chr : t) {
            if (ocr[chr - 'a'] == 0) {
                return false;
            }
            ocr[chr - 'a']--;
        }
        return true;
    }
};