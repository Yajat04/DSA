class Solution {
    //Sliding window as two ptr and window come into play
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int maxLen = 0;
        queue<int> q;
        for(int right = 0; right < n; right++){
            if(nums[right] == 0){
                if(k == 0){ //As queue cant handle it, we have to restart the strings after zeros
                    left = right + 1;
                    continue;
                }
                else if(q.size() == k){
                    int idx = q.front();
                    q.pop();
                    left = idx + 1;
                }
                q.push(right);
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};