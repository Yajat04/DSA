class Solution {
    void bfs(int sr, int sc, vector<vector<char>>& grid, queue <pair<int, int>> &q, 
                vector <vector<bool>> &vis){
        q.push({sr, sc});
        vis[sr][sc] = 1;

        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int r = front.first;
            int c = front.second;
            
            //shortcut for 8 directions
            // for(int dx = -1; dx <= 1; dx++){
            //     for(int dy = -1; dy <= 1; dy++){

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n
                    && !vis[nr][nc] && grid[nr][nc] == '1'){
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }

        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        //core diff is in prev questions, the boundary elements were excluded
        //here we gonna include all types of 1s forming an island, inner or outer(as outer are assumed to be surrounded by water)
        //here we dont count the cells, but count the whole bundle as one
        //Not a multisource problem but a number of connected components problem

        int m = grid.size();
        int n = grid[0].size();
        //bool vis[m][n]; in case of dynamic sized 2d arrays use vector instead
        vector <vector<bool>> vis(m, vector <bool> (n));

        queue <pair<int, int>> q;
        //Logic is for each complete traversal(bfs) queue becomes empty, therefore for each new bfs call the cnt increases;

        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, grid, q, vis);
                }
            }
        }

        return cnt;


    }
};