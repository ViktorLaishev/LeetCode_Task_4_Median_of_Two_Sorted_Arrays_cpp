class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int middle = total / 2;
        int i = 0, j = 0;
        double median, prev = 0, curr = 0;
        
        while (i + j <= middle) {
            prev = curr;
            if (i == m || (j < n && nums2[j] <= nums1[i])) {
                curr = nums2[j++];
            } else {
                curr = nums1[i++];
            }
        }
        
        if (total % 2 == 0) {
            median = (prev + curr) / 2;
        } else {
            median = curr;
        }
        
        return median;
    }
};