class Solution {
    void combinations(int i, vector<int>& candidates, vector<int>& temp, int target, 
                        vector<vector<int>> &ans){
        if(target == 0) {
            ans.push_back(temp);
            return;
        }

        for(int idx = i; idx < candidates.size(); idx++){
            if(idx > i && candidates[idx] == candidates[idx-1]) continue;
            if(candidates[idx] > target) break;

            //take
            temp.push_back(candidates[idx]);
            combinations(idx+1, candidates, temp, target-candidates[idx], ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        combinations(0, candidates, temp, target, ans);

        return ans;
    }
};