class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 1, high = 0;
        for (const int& battery: batteries) {
            high += battery;
        }
        high /= n;

        while (low < high) {
            long long mid = (low + high + 1) / 2, time = 0;

            for (const int& battery: batteries) {
                time += min((long long) battery, mid);
            }
            if (mid * n <= time) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
