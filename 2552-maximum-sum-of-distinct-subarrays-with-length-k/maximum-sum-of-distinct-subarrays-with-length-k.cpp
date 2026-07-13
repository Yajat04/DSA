class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        unordered_map <int, int> freq;
        long long int sum = 0;
        long long int ans = 0;
        
        for(int right = 0; right < nums.size(); right++){
            //Move right only until window becomes k sized, do not put in ans until it become k
            //for < k
            sum += nums[right];
            freq[nums[right]]++;

            //If the first conditio gets invalidated, resolve it before checking for ans
            //for > k
            if(right - left + 1 > k){
                sum -= nums[left];

                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                //It makes sure that the element leaving the window should be removed form map as it should not affect the window size (related to size of map)
                left++;
            }

            //Checking both condition
            //first required even after > k is checked above because initially it was < k
            //for = k

            //Sec Condt : freq[nums[right]] == 1 is wrong as it only confirms for the newer element to be one(no repeat) but it doesnt track if there any repeated els throughout the window
            //Like there are two 2's in the window, when the winndow moves forward either of them may went out or stays but at the current moment we dont have their track so how ould we include the windpw in ans;

            //Therefore freq.size() == k always take care if duplicate is still present or not as, while any duplicate remains in the map the map size will always be less than k since ex: two(val, 1) pairs will merge to form (val, 2) {to imagine} 
            if(right - left + 1 == k && freq.size() == k) ans = max(ans, sum);
        }

        return ans;
        
    }
};