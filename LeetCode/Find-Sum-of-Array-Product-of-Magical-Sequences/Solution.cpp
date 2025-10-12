#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;
using ll = long long;

ll modpow(ll a, ll e) {
    ll r = 1 % MOD;
    a %= MOD;
    while (e) {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int addmod(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}
int mulmod(ll a, ll b) { return (int)((a * b) % MOD); }

class Solution {
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();

        // Precompute factorials & inverse factorials
        vector<ll> fact(m + 1, 1), invfact(m + 1, 1);
        for (int i = 1; i <= m; i++)
            fact[i] = fact[i - 1] * i % MOD;
        invfact[m] = modpow(fact[m], MOD - 2);
        for (int i = m; i > 0; i--)
            invfact[i - 1] = invfact[i] * i % MOD;

        // Precompute powers nums[i]^cnt
        vector<vector<ll>> powNum(n, vector<ll>(m + 1, 1));
        for (int i = 0; i < n; i++)
            for (int c = 1; c <= m; c++)
                powNum[i][c] = powNum[i][c - 1] * nums[i] % MOD;

        // dp[used][carry][ones]
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
        dp[0][0][0] = 1;

        int extraBits = 6; // safe buffer for carries
        int totalBits = n + extraBits;

        for (int b = 0; b < totalBits; ++b) {
            vector<vector<vector<int>>> next(
                m + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, 0)));
            bool hasIndex = (b < n);

            for (int used = 0; used <= m; ++used) {
                for (int carry = 0; carry <= m; ++carry) {
                    for (int ones = 0; ones <= m; ++ones) {
                        int cur = dp[used][carry][ones];
                        if (!cur)
                            continue;

                        if (hasIndex) {
                            int maxC = m - used;
                            for (int c = 0; c <= maxC; ++c) {
                                int total = carry + c;
                                int bit = total & 1;
                                int newCarry = total >> 1;
                                int newOnes = ones + bit;
                                if (newOnes > m)
                                    continue;

                                ll mul = powNum[b][c] * invfact[c] % MOD;
                                int val = mulmod(cur, mul);

                                next[used + c][newCarry][newOnes] = addmod(
                                    next[used + c][newCarry][newOnes], val);
                            }
                        } else {
                            int total = carry;
                            int bit = total & 1;
                            int newCarry = total >> 1;
                            int newOnes = ones + bit;
                            if (newOnes > m)
                                continue;

                            next[used][newCarry][newOnes] =
                                addmod(next[used][newCarry][newOnes], cur);
                        }
                    }
                }
            }

            dp.swap(next);
        }

        int ways = dp[m][0][k];
        return (int)(ways * fact[m] % MOD);
    }
};