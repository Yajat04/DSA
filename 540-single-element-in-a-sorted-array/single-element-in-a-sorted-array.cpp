class Solution {
    //Sorted array , TC logn -> hints of binary search
    //For BS we think of eliminating one half
    //For mid we check the given condition
    //For elimination we require aother condition to move either side

    //Here condition to choose is:
    //Notice that the pair of elements exactly twice are having indices as:
    //Before the single el (left of it) : (even, odd) 
    //After the single el (right of it) : (odd, even) 

    //hence if mid isnt single then check for its other occ at the respective indices to know the side of single el will be present
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        //Whenever there are multiple conditions to handle, handle those edge cases before hand

        int l = 1; int h = n-2;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid%2 == 0){
                if(nums[mid] == nums[mid-1]) h = mid - 1;
                else l = mid + 1; 
            }
            else{
                if(nums[mid] == nums[mid-1]) l = mid + 1;
                else h = mid - 1; 
            }
        }

        return -1;
    }
};