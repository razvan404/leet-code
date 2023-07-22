class Solution {
private:
    pair<double, double> possibleMoves[8] = { 
        { 1.0, 2.0 }, { 2.0, 1.0 }, { -1.0, 2.0 }, { 2.0, -1.0 },
        { 1.0, -2.0 }, { -2.0, 1.0 }, { -1.0, -2.0 }, { -2.0, -1.0 }
    };
    double cachedMoves[26][26][100]{};

public:
    Solution() {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 100; ++k) {
                    cachedMoves[i][j][k] = -1;
                }
            }
        }
    }

    double knightProbability(int n, int k, int row, int column) {
        double prob;
        if (!(row >= 0 && column >= 0 && row < n && column < n)) {
            return 0.0;
        }
        else if (k == 0) {
            return 1.0;
        }
        else if ((prob = cachedMoves[row][column][k - 1]) != -1) {
            return prob;
        }
        else {
            prob = 0.0;
            for (int i = 0; i < 8; ++i) {
                prob += knightProbability(n, k - 1, row + possibleMoves[i].first, column + possibleMoves[i].second);
            }
            prob /= 8.0;
            cachedMoves[row][column][k - 1] = prob;
            return prob;
        }
    }
};
