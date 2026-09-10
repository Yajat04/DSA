class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int pi = 0; pi < i; pi++){
                if(nums[i] > nums[pi]){
                    if(dp[i] == 1 + dp[pi]) cnt[i] += cnt[pi];
                    else if(dp[i] < 1 + dp[pi]){
                        dp[i] = 1 + dp[pi];
                        cnt[i] = cnt[pi];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) ans += cnt[i];
        }

        return ans;

    }
};