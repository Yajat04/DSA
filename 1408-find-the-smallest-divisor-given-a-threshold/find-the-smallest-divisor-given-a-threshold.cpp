class Solution {
    bool check(int div, vector<int>& nums, int threshold){
        int sum = 0;
        for(int num : nums){
            if(num%div == 0) sum += num/div;
            else sum += num/div + 1;
        }

        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 0;
        for(auto num : nums) high = max(high, num);

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, nums, threshold)) high = mid-1;
            else low = mid+1;
        }

        return low;
    }
};