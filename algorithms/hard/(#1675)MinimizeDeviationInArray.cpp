class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int, vector<int>, less<int>> queue;
        int minNum = INT_MAX, minDeviation = INT_MAX;
        for (auto& num : nums) {
            if (num % 2) {
                num += num;
            }
            if (num < minNum) {
                minNum = num;
            }
            queue.push(num);
        }
        while (true) {
            int maxNum = queue.top();
            queue.pop();
            if (maxNum - minNum < minDeviation) {
                minDeviation = maxNum - minNum;
            }
            if (maxNum % 2) {
                break;
            }
            maxNum >>= 1;
            if (maxNum < minNum) {
                minNum = maxNum;
            }
            queue.push(maxNum);
        }
        return minDeviation;
    }
};