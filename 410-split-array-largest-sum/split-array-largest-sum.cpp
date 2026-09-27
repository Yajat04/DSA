class Solution {
    //Array to be splitted, therefore all elements to be taken
    //partitions can be k and should be non empty, therefore atleast one subarr to each partition
    //hence similar to book allocation
    bool validPermute(int maxSum, vector<int>& nums, int k){
        int partitions = 1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] + sum <= maxSum) sum = nums[i] + sum;
            else{
                partitions++;
                sum = nums[i];
            }
        }

        return partitions <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for(int i = 0; i < nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }

        while(low <= high){
            int mid = low + (high-low)/2;
            if(validPermute(mid, nums, k)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};