class Solution {
    int cntSub(int tar, vector<int>& nums){
        if(tar < 0) return 0;
        int cnt = 0;
        int r = 0; int l = 0;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r]%2;
            while(sum > tar){
                sum -= nums[l++]%2;
            }
            cnt += r - l + 1;
            r++;
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k >= n) return 0;

        return cntSub(k, nums) - cntSub(k-1, nums);
    }
};