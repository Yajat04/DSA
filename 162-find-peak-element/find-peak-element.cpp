class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m = nums.size();

        if(m == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[m-1] > nums[m-2]) return m-1;

        int low = 1;
        int high = m-2;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if(nums[mid] > nums[mid-1]) low = mid+1;
            else if(nums[mid] > nums[mid+1]) high = mid-1; 

            else low = mid+1;
        }

        return -1;
    }
};