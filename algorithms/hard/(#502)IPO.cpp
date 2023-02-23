class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> capitalProfit(n);
        for (int i = 0; i < n; ++i) {
            capitalProfit[i] = { capital[i], profits[i] };
        }
        sort(capitalProfit.begin(), capitalProfit.end());
        int i = 0;
        priority_queue<int, vector<int>, less<int>> bestCapital;
        while (k--) {
            while (i < n && w >= capitalProfit[i].first) {
                bestCapital.push(capitalProfit[i].second);
                ++i;
            }
            if (bestCapital.empty()) {
                break;
            }
            w += bestCapital.top();
            bestCapital.pop();
        }
        return w;
    }
};