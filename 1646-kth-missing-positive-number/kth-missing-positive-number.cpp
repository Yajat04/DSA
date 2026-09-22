class Solution {
    //Logic is if there arnt any missing nu =m then for inc sorted order of nums
    //num "i+1" must be present at ith index
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int missing = arr[mid] - (mid+1);
            if(missing < k) low = mid+1;
            else high = mid-1;

        }
        
        return low + k;
    }
};