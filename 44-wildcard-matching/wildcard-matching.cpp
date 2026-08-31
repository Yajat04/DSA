class Solution {
    bool helper(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp){
        if(i1 < 0) return i2 < 0; 
        //Both needs to be exhausted simultaneously for complete match, if i2 left then false
        if(i2 < 0){ //Only be true if all the i1's left are '*' only (empty matching validates)
            for(int i = 0; i <= i1; i++){
                if(s1[i] != '*') return false;
            }
            return true;
        }

        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(s1[i1] == s2[i2] || s1[i1] == '?')
            return dp[i1][i2] = helper(i1-1, i2-1, s1, s2, dp);
        
        if(s1[i1] == '*')
            return dp[i1][i2] = helper(i1-1, i2, s1, s2, dp) | helper(i1, i2-1, s1, s2, dp);

        return dp[i1][i2] = false; //Usual not match, and since it is not subsequnce matching but a continious matching it will cause incomplete match bw s1 and s2
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); //exchanges m and n as per my approach
        return helper(m-1, n-1, p, s, dp);

    }
};