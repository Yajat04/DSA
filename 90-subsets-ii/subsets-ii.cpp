class Solution {
    void powerSet(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>> &ans) {
        ans.push_back(temp);
        for(int idx = i; idx < nums.size(); idx++){
            if(idx > i && nums[idx] == nums[idx-1]) continue;

            //take
            temp.push_back(nums[idx]);
            powerSet(idx+1, nums, temp, ans);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        powerSet(0, nums, temp, ans);

        return ans;
    }
};