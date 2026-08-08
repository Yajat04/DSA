class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = nums[0];
        for(int i = 1; i < n; i++){
            xorr = xorr ^ nums[i];
        }

        return xorr;
    }
};