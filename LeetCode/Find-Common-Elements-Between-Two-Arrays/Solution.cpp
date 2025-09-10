class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        // store unique elements for quick lookup
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        int answer1 = 0, answer2 = 0;

        // count nums1[i] that exists in nums2
        for (int x : nums1) {
            if (set2.count(x))
                answer1++;
        }

        // count nums2[i] that exists in nums1
        for (int y : nums2) {
            if (set1.count(y))
                answer2++;
        }

        return {answer1, answer2};
    }
};
