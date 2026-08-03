class Solution {
    vector <int> org;
public:
    Solution(vector<int>& nums) {
        org = nums;
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        vector <int> ans = org;
        for(int i = 0; i < ans.size(); i++){
            int r = i + rand()%(ans.size() - i); 
            //Gives random index from i to size-1, the randomness still preserves even if the choosing space decreases with each next i
            swap(ans[i], ans[r]); //After this the ith index is fixed and next indices are taken in account
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */