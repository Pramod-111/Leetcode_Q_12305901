class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1, freq2;

        // store frequency of elements in nums1
        for (int x : nums1) {
            freq1[x]++;
        }

        // store frequency of elements in nums2
        for (int y : nums2) {
            freq2[y]++;
        }

        int answer1 = 0, answer2 = 0;

        // count nums1[i] that exists in nums2
        for (int x : nums1) {
            if (freq2.count(x))
                answer1++;
        }

        // count nums2[i] that exists in nums1
        for (int y : nums2) {
            if (freq1.count(y))
                answer2++;
        }

        return {answer1, answer2};
    }
};
