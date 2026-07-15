class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // dist[i][j] = minimum effort required to reach cell (i,j)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        // {effort, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0, {0, 0}});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            // Ignore outdated entries
            if (currEffort > dist[row][col])
                continue;

            // Destination reached
            if (row == m - 1 && col == n - 1)
                return currEffort;

            for (int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {

                    // Difference of the current edge
                    int edgeDiff = abs(heights[row][col] - heights[nr][nc]);

                    // Effort of the complete path till neighbour
                    int newEffort = max(currEffort, edgeDiff);

                    // Found a better path
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;

    }
};