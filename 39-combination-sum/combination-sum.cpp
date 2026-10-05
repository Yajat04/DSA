class Solution {
    //since elements are distinct there is one path possible with one combination therefore no worry for duplicate combos
    void combinations(int i, vector<int>& candidates, vector<int>& temp, int target, 
                        vector<vector<int>> &ans){
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        if(i == candidates.size() || target < 0) return;

        //take
        temp.push_back(candidates[i]);
        combinations(i, candidates, temp, target-candidates[i], ans);
        temp.pop_back();

        //not take
        combinations(i+1, candidates, temp, target, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        combinations(0, candidates, temp, target, ans);
        return ans;

    }
};