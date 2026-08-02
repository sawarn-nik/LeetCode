class Solution {
private:
    int f(int n, vector<int>& dp) {
        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = f(n - 1, dp) + f(n - 2, dp);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};