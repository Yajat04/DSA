class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue < pair < int, int >> q;

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
            if(board[i][n-1] == 'O') {
                q.push({i, n-1});
                board[i][n-1] = '#';
            }
        }

        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = '#';
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                board[m-1][j] = '#';
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

                //The out bounds are bit more refined as still going on the boundary doesnt make sense
                if(nrow > 0 && nrow < m - 1 && ncol > 0 && ncol < n - 1 
                    && board[nrow][ncol] == 'O'){
                    board[nrow][ncol] = '#';
                    q.push({nrow, ncol});
                }
            }
        }

        //vis vector can be used instead of # but that will take up more space
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};