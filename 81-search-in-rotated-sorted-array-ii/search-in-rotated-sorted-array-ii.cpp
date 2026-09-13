class Solution {
    //Even if your search space(half) contains the rotation point (the pivot), it possible for that half to be mistakenly assumed sorted, giving conditions to be true at the same time, as it ay be pointing to the same element as multiple freq is present of same el
    //Ex: [3, 1, 2, 3, 3, 3, 3] hence old solution (unique el) wont work here as it may enter wrong half where el not present
    //The main issue is if alow = amid = ahigh then we cant figure out which one is sorted using only these three ptrs, as we need to enter the unsorted half as the sorted here will contain only the same element if the condtn is true, hence we just shrink the search space from both ends
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue; //Will do shrinking until the usual case comes up
            }

            if(nums[low] <= nums[mid]){ //means left is sorted half
                if(nums[low] <= target && target <= nums[mid]) high = mid -1; 
                else low = mid + 1; 
            }
            else{ //means right is sorted
                if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                else high = mid - 1;
            }
        }

        return false;
    }
};