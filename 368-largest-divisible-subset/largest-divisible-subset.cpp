class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for(int i = 0; i < n; i++) hash[i] = i;

        sort(nums.begin(), nums.end());

        int maxi = -1;
        int lastidx = 0;
        for(int i = 0; i < n; i++){
            for(int pi = 0; pi < i; pi++){
                if(nums[i] % nums[pi] == 0 && dp[i] < 1 + dp[pi]){
                    dp[i] = 1 + dp[pi];
                    hash[i] = pi;
                }

                if(maxi < dp[i]){
                    maxi = dp[i];
                    lastidx = i;
                }
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastidx]);

        while(lastidx != hash[lastidx]){
            lastidx = hash[lastidx];
            ans.push_back(nums[lastidx]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};