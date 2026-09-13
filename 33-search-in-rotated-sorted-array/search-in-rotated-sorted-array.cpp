class Solution {
    //Search + sort => BS
    //Since initially the arr was sorted therefore after rotation also one side of each element will be sorted and other may comprise both lower or greater els
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return mid;
            if(nums[low] <= nums[mid]){ //means left is sorted half since org arr is ascending
                if(nums[low] <= target && target <= nums[mid]) high = mid -1; 
                //Include '=' as it will handle when mid, low ptr on same el
                ///Can only apply condiditon once we know it is sorted
                //As the org array was sorted hence if the el exist then it will exist in the sorted range
                //Like if 2 exist and then it will exist between 1 and 3, it cant happen that 2 1 and 3 exist simultaneously and 2 existing in other part
                else low = mid + 1; //If greater or smaller than sorted range then it may exist in other part
                //Since array doest change after we start searching therefore l and h covers ends from start, therefore the elimination will not lead to skipping the target element (prior low or post high)
            }

            //Put in else as same thing may repeat if both became true
            else{ //means right is sorted
                if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                else high = mid - 1;
            }
        }

        return -1;

    }
};