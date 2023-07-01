class Solution {
private:
    void backtracking(vector<int>& cookies, vector<int>& distributions, unsigned currentIdx, int& minUnfairness) {
        int currentUnfairness = *max_element(distributions.begin(), distributions.end());
        if (currentUnfairness >= minUnfairness) {
            return;
        }
        if (currentIdx == cookies.size()) {
            minUnfairness = currentUnfairness;
            return;
        }
        for (auto& distribution : distributions) {
            distribution += cookies[currentIdx];
            backtracking(cookies, distributions, currentIdx + 1, minUnfairness);
            distribution -= cookies[currentIdx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int minUnfairness = INT_MAX;
        vector<int> distributions(k, 0);
        backtracking(cookies, distributions, 0, minUnfairness);
        return minUnfairness;
    }
};