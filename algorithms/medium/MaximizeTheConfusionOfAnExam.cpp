class Solution {
private:
    inline int getIndex(char chr) {
        return chr - 'F' != 0;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0, freq[2] = {0}, maxFreq = 0;
        for (int right = 0; right < answerKey.size(); ++right) {
            int current = getIndex(answerKey[right]);
            ++freq[current];
            maxFreq = max(maxFreq, freq[current]);
            
            if (right - left + 1 > maxFreq + k) {
                --freq[getIndex(answerKey[left])];
                ++left;
            }
        }
        return answerKey.size() - left;
    }
};