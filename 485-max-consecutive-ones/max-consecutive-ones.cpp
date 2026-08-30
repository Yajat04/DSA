class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        int len = 0;
        for(auto num : nums){
            if(num == 1) len++;
            else len = 0;
            maxi = max(maxi, len);
        }

        return maxi;

    }
};