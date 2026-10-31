class Solution {
    int MOD = 1e9 + 7;
    int countPaths(int i, int j, bool flag, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        int up = 0;
        int left = 0;
        if(grid[i][j] == 1){
            if(flag) left = countPaths(i, j-1, 0, grid, dp);
            else up = countPaths(i-1, j, 1, grid, dp);
        }
        else{
            up = countPaths(i-1, j, 1, grid, dp);
            left = countPaths(i, j-1, 0, grid, dp);
        }

        return dp[i][j][flag] = (left + up)%MOD;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[m-1][n-1] == 1 || grid[0][0] == 1) return 0;

        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (2, -1)));
        return countPaths(m-1, n-1, 0, grid, dp);
    }
};