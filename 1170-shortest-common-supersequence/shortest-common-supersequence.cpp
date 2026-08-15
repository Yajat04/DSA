class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int i1 = m;
        int i2 = n;
        string ans = "";
        while(i1 > 0 && i2 > 0){
            if(str1[i1-1] == str2[i2-1]){
                ans.push_back(str1[i1-1]);
                i1--;
                i2--;
            }

            else if(dp[i1-1][i2] > dp[i1][i2-1]){
                ans.push_back(str1[i1-1]);
                i1--;
            }
            else{
                ans.push_back(str2[i2-1]);
                i2--;
            }
        }

        while(i1 > 0){
            ans.push_back(str1[i1-1]);
            i1--;
        }
        while(i2 > 0){
            ans.push_back(str2[i2-1]);
            i2--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};