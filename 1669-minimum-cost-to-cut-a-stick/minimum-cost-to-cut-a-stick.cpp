class Solution {
    int minCost(int i, int j, vector<int>& cuts, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int idx = i; idx <= j; idx++){
           int cost = cuts[j+1] - cuts[i-1] + minCost(i, idx-1, cuts, dp) + minCost(idx+1, j, cuts, dp);
            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int> (m, -1));

        return minCost(1, m-2, cuts, dp);
    }
};