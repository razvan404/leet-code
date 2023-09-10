class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> elems;
        elems.push_back({ 1 });
        for (int i = 1; i < numRows; ++i) {
            elems.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                elems[i][j] = elems[i - 1][j - 1] + elems[i - 1][j];
            }
        }
        return elems;
    }
};
