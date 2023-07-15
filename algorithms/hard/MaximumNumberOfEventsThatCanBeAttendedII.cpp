class Solution {
private:
    int binarySearch(vector<vector<int>>& events, int left, int biggerThan) {
        int right = events.size() - 1, ans = -1;
        while (right >= left) {
            int mid = (left + right) / 2;
            if (events[mid][0] > biggerThan) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int helper(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if (i >= events.size() || k == 0 || i == -1) {
            return 0;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        int idx = binarySearch(events, i + 1, events[i][1]);
        int c1 = events[i][2] + helper(idx, events, k - 1, dp);
        int c2 = helper(i + 1, events, k, dp);
        return dp[i][k] = max(c1, c2);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>>dp(events.size(), vector<int>(k + 1, -1));
        return helper(0, events, k, dp);
    }
};
