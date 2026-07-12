class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int mini = INT_MAX;
        int sum = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                mini = min(mini, right - left + 1);
                sum -= nums[left];
                left++;
            }
        //The order of sum+, and while matters because you should first make the window valid (by adding nums[right]) and only then try to minimize it (by shrinking from the left).
        //mini only makes sense when it reaches valid sum
        }

        if(mini == INT_MAX) return 0;
        //if(sum < target) return 0; not valid condition as there may be case where mini is possible but the final window may have sum lesser than target and it may give false negative

        return mini;
    }
};