class Solution {
    int maxCost(int i, int j, vector<int>& nums, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN;
        for(int idx = i; idx <= j; idx++){
            int cost = nums[i-1] * nums[idx] * nums[j+1] + 
                        maxCost(i, idx-1, nums, dp) + maxCost(idx+1, j, nums, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return maxCost(1, n-2, nums, dp);
    }
};