class Solution {
    int daysWithinCapacity(vector<int>& weights, int maxCapacity) {
        int days = 0, currentSum = 0;
        for (const auto& weight : weights) {
            if (currentSum + weight > maxCapacity) {
                ++days;
                currentSum = weight;
            }
            else {
                currentSum += weight;
            }
        }
        return days + 1;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN; // the maximum weight, it's the minimum capacity
        int right = 0; // the sum of the weights, it's the maximum capacity

        for (const auto& weight : weights) {
            right += weight;
            if (weight > left) {
                left = weight;
            }
        }

        while (left < right) {
            int mid = (left + right) / 2;
            if (daysWithinCapacity(weights, mid) <= days) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};