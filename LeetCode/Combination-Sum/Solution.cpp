class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // dp[i] will store all combinations that sum up to i
        vector<vector<vector<int>>> dp(target + 1);

        // Base: dp[0] = empty combination
        dp[0].push_back({});

        for (int num : candidates) {
            for (int t = num; t <= target; t++) {
                // if there's a way to make (t - num), extend it with num
                for (auto comb : dp[t - num]) {
                    comb.push_back(num);
                    dp[t].push_back(comb);
                }
            }
        }

        return dp[target];
    }
};
