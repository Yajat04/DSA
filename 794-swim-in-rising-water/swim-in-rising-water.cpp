class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        int timmer = 0;
        while(!pq.empty()){
            auto [h, r, c] = pq.top();
            while(h > timmer) timmer++;
            pq.pop();

            if(r == m-1 && c == n-1) return timmer;
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0){
                    pq.push({grid[nr][nc], nr, nc});
                    vis[nr][nc] = 1;    
                }
            }
        }

        return -1;
    }
};