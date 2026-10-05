class Solution {
    void powerSet(int i, vector<int>& nums, vector<int> &temp, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        powerSet(i+1, nums, temp, ans);
        temp.pop_back();

        //not take
        powerSet(i+1, nums, temp, ans);

        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        powerSet(0, nums, temp, ans);
        
        return ans;
    }
};