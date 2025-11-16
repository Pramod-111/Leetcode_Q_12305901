class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long ans = 0;
        long long ones = 0; 

        for (char c : s) {
            if (c == '1') {
                ones++;              
                ans = (ans + ones) % MOD; 
            } else {
                ones = 0; 
            }
        }

        return ans;
    }
};