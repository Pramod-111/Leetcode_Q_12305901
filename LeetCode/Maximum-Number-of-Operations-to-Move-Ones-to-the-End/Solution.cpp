class Solution {
public:
    int maxOperations(string s) {
        long long ans = 0;
        long long ones = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++ones;
            } else { 
                if (i == n - 1 || s[i + 1] == '1') {
                    ans += ones;
                }
            }
        }
        return ans;
    }
};