class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        int mini = 1e9;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[low] <= nums[mid]){ //means left is sorted half
                mini = min(mini, nums[low]);
                low = mid + 1;
            }
            else{ //means right is sorted
                mini = min(mini, nums[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }
};