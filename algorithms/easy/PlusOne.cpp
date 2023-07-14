class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result = digits;
        for (int i = result.size() - 1; i >= 0; --i) {
            if (result[i] != 9) {
                result[i] += 1;
                return result;
            }
            result[i] = 0;
        }
        result.push_back(0);
        result[0] = 1;
        return result;
    }
};