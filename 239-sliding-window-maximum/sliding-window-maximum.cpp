class Solution {
    //Maintaing max for each window
    //requires comparison from back of the queue and also require poping and pushing from the back, hence deque required
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque <int> dq;
        vector <int> ans;

        int left = 0;
        for(int right = 0; right < n; right++){
            while(!dq.empty() && nums[right] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(right);

            if(right >= k-1) {
                ans.push_back(nums[dq.front()]);
                if(left == dq.front()) dq.pop_front();
                left++;
            }
        }

        return ans;
    }
};