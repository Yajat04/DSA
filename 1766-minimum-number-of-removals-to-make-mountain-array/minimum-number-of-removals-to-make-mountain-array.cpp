class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        for(int i = 0; i < n; i++){
            for(int pi = 0; pi < i; pi++){
                if(nums[i] > nums[pi]) dp1[i] = max(dp1[i], 1 + dp1[pi]);
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int pi = n-1; pi > i; pi--){
                if(nums[i] > nums[pi]) dp2[i] = max(dp2[i], 1 + dp2[pi]);
            }
        }

        int maxi = 0;
        for(int i = 0; i< n; i++){
            if(dp1[i] > 1 && dp2[i] > 1)
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }

        return n - maxi;

    }
};