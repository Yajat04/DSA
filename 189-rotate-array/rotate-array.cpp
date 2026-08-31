class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int r = k % nums.size(); //To wrap k if k > n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + r);
        reverse(nums.begin() + r, nums.end());
    }
};