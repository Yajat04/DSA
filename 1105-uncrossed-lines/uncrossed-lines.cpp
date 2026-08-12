class Solution {
    int lcs(int i1, int i2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(nums1[i1] == nums2[i2]) return dp[i1][i2] = 1 + lcs(i1-1, i2-1, nums1, nums2, dp);
        return dp[i1][i2] = max(lcs(i1, i2-1, nums1, nums2, dp), 
                                    lcs(i1-1, i2, nums1, nums2, dp));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return lcs(m-1, n-1, nums1, nums2, dp);
    }
};