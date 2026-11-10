class Solution {
    long long minCost(int i, vector<int>& costs, vector <long long> &dp){
        if(i == 0) return 0;
        if(dp[i] != -1) return dp[i];

        long long take1 = LLONG_MAX;
        if(i-1 >= 0) take1 = 1 + costs[i-1] + minCost(i-1, costs, dp);

        long long take2 = LLONG_MAX;
        if(i-2 >= 0) take2 = 4 + costs[i-1] + minCost(i-2, costs, dp);

        long long take3 = LLONG_MAX;
        if(i-3 >= 0) take3 = 9 + costs[i-1] + minCost(i-3, costs, dp);

        return dp[i] = min(take1, min(take2, take3));
    }
public:
    int climbStairs(int n, vector<int>& costs) {
        vector <long long> dp(n+1, -1);
        return minCost(n, costs, dp);
    }
};