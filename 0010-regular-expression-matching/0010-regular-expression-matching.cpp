class Solution {
private:
    string a, b;
    int dp[21][21];
public:
    bool fun(int i, int j) {
        if (j < 0) return i < 0;
        if (i < 0) {
            if (b[j] == '*') return fun(i, j - 2);
            return false;
        }
        if (dp[i][j] != -1) return dp[i][j];

        bool check = false;

        if (b[j] == '*') {
            check = fun(i, j - 2) || ((a[i] == b[j - 1] || b[j - 1] == '.') && fun(i - 1, j));
        } else {
            check = (a[i] == b[j] || b[j] == '.') && fun(i - 1, j - 1);
        }

        dp[i][j] = check ? 1 : 0;
        return check;
    }

    bool isMatch(string s, string p) {
        a = s; 
        b = p;
        memset(dp, -1, sizeof(dp));
        return fun(a.size() - 1, b.size() - 1);
    }
};
