class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue <pair<pair<int, int>, int>> q;
        int vis[m][n];

        int cntFresh = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; //In this question "2" means vis = True
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) cntFresh++;
            }
        }

        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto front = q.front();
            int r = front.first.first;
            int c = front.first.second;
            int t = front.second;

            tm = max(tm, t);

            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0
                    && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                        cntFresh--; 
                }
            }
        }

        if(cntFresh == 0) return tm;
        return -1;
    }
};