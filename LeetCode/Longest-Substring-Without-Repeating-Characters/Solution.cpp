class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // stores last index of each character
        int maxLen = 0;
        int left = 0; // left pointer of the sliding window

        for (int right = 0; right < s.length(); right++) {
            // if character already seen, move left pointer
            if (lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right;            // update last seen index
            maxLen = max(maxLen, right - left + 1); // update max length
        }

        return maxLen;
    }
};
