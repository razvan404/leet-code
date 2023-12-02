class Solution {
private:
    int numsOf1(vector<int>& row) {
        int left = 0, right = row.size() - 1;
        if (row[right] == 1) {
            return row.size();
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (row[mid] == 1 && row[mid + 1] == 0) {
                return mid + 1;
            } else if (row[mid] == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> firstKPairs(k, {0, 0});
        for (int i = 0; i < k; ++i) {
            firstKPairs[i].second = i;
            firstKPairs[i].first = numsOf1(mat[i]);
        }
        priority_queue<pair<int, int>> pq(firstKPairs.begin(), firstKPairs.end());
        for (int i = k; i < mat.size(); ++i) {
            pq.push({numsOf1(mat[i]), i});
            pq.pop();
        }
        vector<int> ans(k, 0);
        for (int i = k - 1; i >= 0; --i) {
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};