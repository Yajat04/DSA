class Solution {
    // consecutive elements -> sort + sliding window?
    // sliding window will not be efficient as the value of starting point can also change and once it changes, the rest of the scenario will update therefore it will hit tle
    // after sorting also we could pick elements from any forward index to form subsequence
    // therfore too much to try hence use recursion

    // for having or making consecutive seq for the current x call it requires x or x + 1 at any forward index
    // we sorted because we could find that elment in logn time using binary search
    // we are thinking that we will find it on next index as it is sorted but think that we may have increased the element on the prev calls so now the org array may not have the reqd element right next to it

    // Too much chaos fall back to recursion
    int findSeq(int i, int inc, vector<int>& nums, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][inc] != -1) return dp[i][inc];

        int tofind = nums[i] + inc;

        int take = 0;

        // For the same element as curr el
        // if finds the same element then on further call for that element, the that element must be 
        int tofind_idx = lower_bound(nums.begin() + i + 1, nums.end(), tofind) - nums.begin(); 
        if(tofind_idx < nums.size() && nums[tofind_idx] == tofind)
            take = max(take, findSeq(tofind_idx, 1, nums, dp));
        // if same el like, 1 -> 1 then the next 1 should go in as 2 therefore inc = 1 (means we are inc it on our own)
        // so that 1 -> 2 -> .... instead of 1 -> 1 -> ..... as the final sequence
        
        //nums.begin() + i + 1,
        //find the next el if it exist, if it does then it must be on any fwd index as the arr is sorted
        //it also avoids to encounter the element itself or less for inc = 0, and that would cause infinite loop

        // for the curr + 1 el 
        tofind_idx = lower_bound(nums.begin() + i + 1, nums.end(), tofind+1) - nums.begin(); 
        if(tofind_idx < nums.size() && nums[tofind_idx] == tofind + 1)
            take = max(take, findSeq(tofind_idx, 0, nums, dp));

        return dp[i][inc] = 1 + take; //added one to include current element
    }
public:
    int maxSelectedElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int> (2, -1));
        int result = 0;
        for(int i = 0; i < n; i++){
            result = max(
                        max(
                            findSeq(i, 0, nums, dp),
                            findSeq(i, 1, nums, dp)
                        ),
                        result
            );
        }

        return result;
    }
};