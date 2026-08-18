class Solution {
    bool jump(int idx_currStone, int prevJump,vector<int>& stones, int dp[][2001], unordered_map <int, int> &mp){
        if(idx_currStone == stones.size()-1) return true;
        if(dp[idx_currStone][prevJump] != -1) return dp[idx_currStone][prevJump];

        bool result = false;
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++){
            if(nextJump <= 0) continue;
            int nextStone = stones[idx_currStone] + nextJump;
            if(mp.find(nextStone) != mp.end()){
                result = result || jump(mp[nextStone], nextJump, stones, dp, mp);
            }
        }
        return dp[idx_currStone][prevJump] = result;

    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int dp[2001][2001];
        memset(dp, -1, sizeof(dp));

        unordered_map <int, int> mp;
        for(int i = 0; i<n; i++) mp[stones[i]] = i;
        return jump(0, 0, stones, dp, mp);
    }
};