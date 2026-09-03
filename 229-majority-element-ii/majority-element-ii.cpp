class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> freq;
        for(auto x : nums){
            if(++freq[x] == n/3 + 1) ans.push_back(x);
        }
        return ans;
    }
};