class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        
        queue < pair < int, pair < int, int >>> q;
        vector < vector < bool >> vis (n, vector < bool > (n));

        vis[0][0] = 1;
        q.push({1, {0, 0}});

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            auto front = q.front();
            q.pop();

            int d =  front.first;
            int r =  front.second.first;
            int c =  front.second.second;

            for(int i = 0; i < 8; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];

                if(nr == n-1 && nc == n-1) return d + 1;

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 
                    && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    q.push({d + 1, {nr, nc}});
                }
            }
        }

        return -1;
    }
};

//Not optimal since it has constant edge wt hence normaal bfs is enough