class Solution {
    void solve(int col, int &n, vector<string> &board, vector<vector<string>> &ans,
                vector<int> &leftrow, vector<int> &leftlowerdiag, vector<int> &leftupperdiag){
        if(col == n){ //will reach here only if it is able to place all queens safely
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(!leftrow[row] && !leftlowerdiag[row+col] && !leftupperdiag[n-1+col-row]){
                leftrow[row] = leftlowerdiag[row+col] = leftupperdiag[n-1+col-row] = 1;
                board[row][col] = 'Q';
                solve(col+1, n, board, ans, leftrow, leftlowerdiag, leftupperdiag);
                board[row][col] = '.';
                leftrow[row] = leftlowerdiag[row+col] = leftupperdiag[n-1+col-row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> leftrow(n, 0), leftlowerdiag(2*n-1, 0), leftupperdiag(2*n-1, 0);

        string s(n, '.');
        for(int i = 0; i < n; i++) board[i] = s;

        solve(0, n, board, ans, leftrow, leftlowerdiag, leftupperdiag);

        return ans;
    }
};