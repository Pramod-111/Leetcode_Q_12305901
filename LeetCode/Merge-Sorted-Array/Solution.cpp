class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;     // pointer for nums1
        int j = n - 1;     // pointer for nums2
        int k = m + n - 1; // pointer for placement in nums1

        // Compare from the back and place the larger element at the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If elements are left in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
        // No need to copy nums1's remaining elements since they are already in
        // place
    }
};
