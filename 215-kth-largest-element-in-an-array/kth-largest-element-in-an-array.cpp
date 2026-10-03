class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = nums.size();
        int i = 0;
        while(i < n){
            if(i < k) pq.push(nums[i]);
            else if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }

        return pq.top();
    }
};