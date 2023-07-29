class Solution {
private:
    double backtracking(int quantityA, int quantityB, vector<vector<double>>& cached) {
        if (quantityA <= 0) {
            if (quantityB <= 0) {
                return 0.5;
            }
            return 1.0;
        }
        else if (quantityB <= 0) {
            return 0.0;
        }
        double prob;
        if ((prob = cached[quantityA - 1][quantityB - 1]) != -1) {
            return prob;
        }
        prob = 0.0;
        for (int i = 0; i < 4; ++i) {
            prob += backtracking(quantityA - 4 + i, quantityB - i, cached);
        }
        prob /= 4.0;
        cached[quantityA - 1][quantityB - 1] = prob;
        return prob;
    }
public:
    double soupServings(int n) {
        if (n > 4050) {
            return 99999e-5;
        }
        int relaxedN = n / 25;
        if (n % 25) {
            relaxedN++;
        }
        vector<vector<double>> cached(relaxedN, vector<double>(relaxedN, -1.0));
        return backtracking(relaxedN, relaxedN, cached);
    }
};
