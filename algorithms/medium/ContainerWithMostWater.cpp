class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxim = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            if (area > maxim) {
                maxim = area;
            }
            if (height[left] < height[right]) {
                ++left;
            }
            else if (height[right] < height[left]) {
                --right;
            }
            else {
                ++left;
                --right;
            }
        }
        return maxim;
    }
};
