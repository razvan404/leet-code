class Solution {
private:
    bool evaluate(int k, vector<int>& dist, double hour) {
        double currentTime = 0;
        for (int i = 0; i < dist.size(); ++i) {
            currentTime = ceil(currentTime) + dist.at(i) * 1.0 / k;
            if (currentTime > hour) {
                return false;
            }
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (hour <= dist.size() - 1) {
            return -1;
        }
        int left = 1, right = 0, ans = -1;
        double scaleFactor = 1 / (hour - dist.size() + 1);
        for (int i = 0; i < dist.size(); ++i) {
            right = max(right, dist.at(i));
        }
        if (scaleFactor > 1) right = ceil(right * scaleFactor);
        while (left <= right) {
            int mid = (left + right) / 2;
            if (!evaluate(mid, dist, hour)) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};
