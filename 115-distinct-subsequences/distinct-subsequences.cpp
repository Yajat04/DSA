class Solution {
    int countWays(int i1, int i2, int (*dp)[1001], string &s, string &t){
        if(i2 < 0) return 1;
        if(i1 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s[i1] == t[i2]) 
            return dp[i1][i2] = countWays(i1-1, i2-1, dp, s, t) + countWays(i1-1, i2, dp, s, t);
        else return dp[i1][i2] = countWays(i1-1, i2, dp, s, t);
    }
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        return countWays(m-1, n-1, dp, s, t);
    }
};