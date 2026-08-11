class Solution {
    int ways(int i, int tar, vector<int>& coins, vector<vector<int>> &dp){
        if(tar == 0) return 1;
        if(i == 0) return (tar % coins[i] == 0);
        if(dp[i][tar] != -1) return dp[i][tar];

        int nt = ways(i-1, tar, coins, dp);
        int t = 0;
        if(coins[i] <= tar) t = ways(i, tar-coins[i], coins, dp);

        return dp[i][tar] = nt + t;

    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return ways(n-1, amount, coins, dp);

    }
};