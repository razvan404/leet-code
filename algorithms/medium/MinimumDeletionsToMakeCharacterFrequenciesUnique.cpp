class Solution {
public:
    int minDeletions(string s) {
        int freq['z' - 'a' + 1]{}, deletions = 0;
        for (const auto& c : s) {
            ++freq[c - 'a'];
        }
        bool freqUnique = false;
        while (!freqUnique) {
            freqUnique = true;
            for (int i = 0; i < 'z' - 'a' + 1; ++i) {
                if (freq[i] == 0) continue;
                for (int j = 0; j < 'z' - 'a' + 1; ++j) {
                    if (freq[j] == 0) continue;
                    if (freq[i] == freq[j] && i != j) {
                        --freq[i];
                        ++deletions;
                        freqUnique = false;
                        --i;
                        break;
                    }
                }
            }
        }
        return deletions;
    }
};
