class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        vector<long long> dp(26, 0);

        for (char c : s) {
            int i = c - 'a';

            long long sum = 1;  // current character alone

            for (int j = 0; j < 26; j++)
                sum = (sum + dp[j]) % MOD;

            dp[i] = sum;
        }

        long long ans = 0;

        for (int x : dp)
            ans = (ans + x) % MOD;

        return ans;
    }
};