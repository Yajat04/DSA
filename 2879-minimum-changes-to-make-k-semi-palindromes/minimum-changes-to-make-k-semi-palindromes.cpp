class Solution {
    int makePalindrome(string s){
        int i = 0;
        int j = s.size()-1;

        int count = 0;
        while(i < j){
            if(s[i] != s[j]) count++;
            i++;
            j--;
        }
        return count;
    }

    int minOp(int l, int h, string &s, vector<vector<int>> &costMemo){
        int n = h - l + 1;
        if(n < 2) return 1e9;
        if(costMemo[l][h] != -1) return costMemo[l][h];

        vector <int> validDivisor;
        for(int i = 1; i < n/2+ 1; i++){
            if(n % i == 0) validDivisor.push_back(i);
        }

        int miniOpr = 1e9;
        for(int i = 0; i < validDivisor.size(); i++){
            int d = validDivisor[i];

            int minChanges = 0;
            for(int j = 0; j < d; j++){
                string subs = "";
                int k = j;
                while(k < n){
                    subs += s[l+k];
                    k += d;
                }
                minChanges += makePalindrome(subs);
            }

            miniOpr = min(miniOpr, minChanges);
            if(miniOpr == 0) break;
        }

        return costMemo[l][h] = miniOpr;
    }

    int minChanges(int i, int k, string &s, vector<vector<int>> &dp, vector<vector<int>> &costMemo){
        int n = s.size();
        if (i == n) return (k == 0 ? 0 : 1e9);
        if (k == 0) return 1e9;
        if(dp[i][k] != -1) return dp[i][k];

        int mini = INT_MAX;
        for(int idx = i; idx < n; idx++){
            int cost = INT_MAX;
            // 1 <= d < len, 
            //Because d must be at least 1 AND strictly less than len
            //If len == 1, the inequality becomes 1 <= d < 1, No integer d exists!
            //The smallest integer len where a valid d exists is len == 2 (which gives 1 <= d < 2, so d = 1)
            if(n - 1 - idx >= 2 * (k - 1)) cost = minOp(i, idx, s, costMemo) + minChanges(idx + 1, k-1, s, dp, costMemo);
            mini = min(mini, cost);
        }
        return dp[i][k] = mini;
    }

public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        vector<vector<int>> costMemo(n, vector<int>(n, -1));
        return minChanges(0, k, s, dp, costMemo);
    }
};