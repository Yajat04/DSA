class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int maxLen = 0;
        queue<int> q;
        for(int right = 0; right < n; right++){
            if(nums[right] == 0){
                if(k == 0){
                    left = right + 1;
                    continue;
                }

                if(k != 0 && q.size() == k){
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