class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long xorr = 0;
        for(int i = 0; i < n; i++) xorr ^= nums[i];

        int mask = (xorr & -(xorr));
        int xor1 = 0;
        int xor2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] & mask) xor1 ^= nums[i];
            else xor2 ^= nums[i];
        }

        return {xor1, xor2};
    }
};