class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            maxVal = max(maxVal, nums[i]);
        }
        
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += maxVal - nums[i];
        }

        return ans;
    }
};