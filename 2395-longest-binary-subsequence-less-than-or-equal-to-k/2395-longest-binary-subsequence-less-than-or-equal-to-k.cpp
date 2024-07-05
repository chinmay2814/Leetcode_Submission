typedef long long ll;

ll dp[1001][1001];

class Solution {

    ll solve(const string &s, ll k, int idx, ll count) {
        if (k < 0) return LLONG_MIN;
        if (idx >= s.length()) return 0;
        if (dp[idx][count] != -1) return dp[idx][count];

        ll res = solve(s, k, idx + 1, count);

        if (count < 32) {
            ll bitValue = ((ll)(s[idx] - '0')) << count;
            if (k >= bitValue) {
                res = max(res, 1 + solve(s, k - bitValue, idx + 1, count + 1));
            }
        } else if (s[idx] == '0') {
            res = max(res, 1 + solve(s, k, idx + 1, count + 1));
        }

        return dp[idx][count] = res;
    }

public:
    int longestSubsequence(string s, int k) {
        memset(dp, -1, sizeof(dp));
        reverse(s.begin(),s.end());
        return solve(s, k, 0, 0);
    }
};