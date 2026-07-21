class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue < pair <int, int> > q;
        vector < vector <bool>> vis (m, vector <bool> (n));

        int cnt = 0;
        int totalcnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1){
                    vis[i][j] = 1;
                    q.push({i, j});
                    cnt++;
                }

                if(grid[i][j] == 1) totalcnt++;
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr > 0 && nr < m-1 && nc > 0 && nc < n-1 
                    && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                    cnt++;
                }
            }
        }

        return totalcnt - cnt;


    }
};