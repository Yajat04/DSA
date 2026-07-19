class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater){
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> ans(m, vector <int> (n, -1));
        queue <pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    ans[i][j] = 0;
                } 
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && ans[nrow][ncol] == -1){
                    ans[nrow][ncol] = ans[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return ans;

    }
};