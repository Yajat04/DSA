class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<
            pair<pair<int, int>, int>,
            vector<pair<pair<int, int>, int>>,
            greater<pair<pair<int, int>, int>>
            > pq;

        pq.push({{0, 0}, 0});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int r = top.first.first;
            int c = top.first.second;
            int e = top.second;

            if(r == m-1 && c == n-1) return dist[m-1][n-1];

            if(e > dist[r][c]) continue; //Dont explore neighbours with old values [Non min val]

            for(int i = 0; i < 4; i++){
                int nrow = r + dx[i];
                int ncol = c + dy[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){ //valid cell
//No need of visited array as there may be node used multiple times to find out the best path
                    int diff = abs(heights[r][c] - heights[nrow][ncol]);
                    int effort = max(e, diff);

                    if(dist[nrow][ncol] > effort){
                        dist[nrow][ncol] = effort;
                        pq.push({{nrow, ncol}, effort});
                    }
                }
            }
        }
        return 0;
    }
};