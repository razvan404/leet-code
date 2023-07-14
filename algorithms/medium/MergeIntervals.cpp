class Solution {
    bool areMergeable(vector<int>& interval1, vector<int>& interval2) {
        return interval2[0] <= interval1[1] || interval1[1] >= interval2[1];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (areMergeable(ans.back(), intervals[i])) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
