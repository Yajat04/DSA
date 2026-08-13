class Solution {
    int lcs(int i1, int i2, string &s, string &sr, vector<vector<int>> &dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s[i1] == sr[i2]) return dp[i1][i2] = 1 + lcs(i1-1, i2-1, s, sr, dp);
        return dp[i1][i2] = max(lcs(i1, i2-1, s, sr, dp), 
                                    lcs(i1-1, i2, s, sr, dp));
    }

public:
    int longestPalindromeSubseq(string s) {
        int m = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(m, vector<int> (m, -1));
        return lcs(m-1, m-1, s, rev, dp);
    }
};