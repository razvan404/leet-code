class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = (int)nums1.size(), m = (int)nums2.size();

        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (n == 0) {
            if (m == 0) {
                return 0;
            }
            else {
                return m % 2 ? nums2[m / 2] : (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
            }
        }

        if (nums1[n - 1] < nums2[0]) {
            if (n == m) {
                return (nums1[n - 1] + nums2[0]) * 1.0 / 2.0;
            }
            else {
                return (n + m) % 2 ? nums2[(m - n) / 2] :
                    (nums2[(m - n) / 2 - 1] + nums2[(m - n) / 2]) / 2.0;
            }
        }
        if (nums2[m - 1] < nums1[0]) {
            if (n == m) {
                return (nums1[0] + nums2[m - 1]) * 1.0 / 2.0;
            }
            else {
                return (n + m) % 2 ? nums2[m - (m - n) / 2 - 1]
                    : (nums2[m - (m - n) / 2 - 1] + nums2[m - (m - n) / 2])  / 2.0;
            }
        }

        int left = 0, right = n, partitionSize = (n + m + 1) / 2;
       
        while (left <= right) {
            int cut1 = (left + right) / 2;
            int cut2 = partitionSize - cut1;

            int left1 = cut1 > 0 ? nums1[cut1 - 1] : INT_MIN, right1 = cut1 < n ? nums1[cut1] : INT_MAX;
            int left2 = cut2 > 0 ? nums2[cut2 - 1] : INT_MIN, right2 = cut2 < m ? nums2[cut2] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                return (n + m) % 2 ? max(left1, left2)
                    : (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else if (left1 > right2) {
                right = cut1 - 1;
            }
            else {
                left = cut1 + 1;
            }
        }
        return 0.0;
    }
};