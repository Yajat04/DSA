class Solution {
    int solve(int i, int sum, vector<int>& nums, vector<vector<int>> &dp){
        if(i == 0){
            if(nums[0] == 0 && sum == 0) return 2; //take or not
            if(sum == 0) return 1; //not take
            return (sum == nums[0]);
        }
        if(dp[i][sum] != -1) return dp[i][sum];

        int not_take = solve(i-1, sum, nums, dp);
        int take = 0;
        if(nums[i] <= sum) take = solve(i-1, sum - nums[i], nums, dp);

        return dp[i][sum] = take + not_take;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for(auto num : nums) totsum += num;

        if(((totsum - abs(target)) < 0) || ((totsum - abs(target)) % 2)) return 0;
        int required = (totsum - abs(target))/2;
        vector<vector<int>> dp(n, vector<int> (required + 1, -1));
        return solve(n-1, required, nums, dp);
    }
};