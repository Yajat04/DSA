class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;

        int maxLen = 1;
        
        int flag = nums[1] > nums[0];
        int left = 0;
        for(int right = 1; right < nums.size(); right++){
            if(nums[right] > nums[right-1]){
                if(flag) maxLen = max(maxLen, right - left + 1);
                else{
                    flag = true;
                    left = right-1;
                }
            }
            else if(nums[right] < nums[right-1]){
                if(flag){
                    flag = false;
                    left = right-1;
                }
                else maxLen = max(maxLen, right - left + 1);
            }
            else{
                left = right;
                if(right+1 < n) flag = nums[right+1] > nums[right];
            }
        }

        return maxLen;
    }
};