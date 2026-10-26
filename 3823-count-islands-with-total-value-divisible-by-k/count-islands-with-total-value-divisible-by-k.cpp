class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue <pair <int, int>> q;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        long long totSum = 0;

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != 0 && vis[i][j] == 0){

                    q.push({i, j});
                    vis[i][j] = 1;
                    totSum = grid[i][j];

                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();

                        for(int i = 0; i < 4; i++){
                            int nr = r + dx[i];
                            int nc = c + dy[i];

                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0 && vis[nr][nc] == 0){
                                totSum += grid[nr][nc];
                                vis[nr][nc] = 1;
                                q.push({nr, nc});
                            }
                        }
                    }

                    if(totSum % k == 0) count++;
                    totSum = 0;
                }
            }
        }

        return count;
    }           
};