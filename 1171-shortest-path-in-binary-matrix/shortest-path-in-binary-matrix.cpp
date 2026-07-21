class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        priority_queue < pair < int, pair < int, int >> ,
                            vector < pair < int, pair < int, int >> > ,
                            greater < pair < int, pair < int, int >> >
                        > pq;
        vector < vector < int >> dist (n, vector < int > (n, INT_MAX));

        dist[0][0] = 1;
        pq.push({1, {0, 0}});

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int d =  top.first;
            int r =  top.second.first;
            int c =  top.second.second;

            if(dist[r][c] < d) continue;

            if(r == n-1 && c == n-1) return dist[r][c];

            for(int i = 0; i < 8; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    if(dist[r][c] + 1 < dist[nr][nc]){
                        dist[nr][nc] = dist[r][c] + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        
        return -1;
    }
};