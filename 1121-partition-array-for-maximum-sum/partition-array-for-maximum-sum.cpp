class Solution {
    int maxSum(int i, vector<int>& arr, int &k, vector<int> &dp){
        if(i == arr.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int maxi = -1;
        int j = i;

        int max_el = -1;
        while(j-i < k && j < arr.size()){
            max_el = max(max_el, arr[j]);
            int cost = max_el * (j-i+1) + maxSum(j+1, arr, k, dp); 
            maxi = max(maxi, cost);
            j++;
        }

        return dp[i] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return maxSum(0, arr, k, dp);
    }
};