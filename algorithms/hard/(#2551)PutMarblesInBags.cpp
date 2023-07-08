class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || k == n) {
            return 0;
        }
        vector<int> aux;
        for (int i = 0; i < n - 1; ++i) {
            aux.push_back(weights[i] + weights[i + 1]);
        }
        sort(aux.begin(), aux.end());
        long long ans = 0;
        for (int i = 0; i < k - 1; ++i) {
            ans += aux[n - i - 2] - aux[i];
        }
        return ans;
    }
};