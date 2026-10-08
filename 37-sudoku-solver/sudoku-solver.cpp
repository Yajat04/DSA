class Solution {
    bool isValid(int row, int col, char num, vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == num) return false;
            if(board[i][col] == num) return false;

            int r = 3 * (row /3)  + i / 3;
            int c = 3 * (col /3)  + i % 3;
            if(board[r][c] == num) return false;
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){//Dont go col by col or row by row, go cell by cell , it would be easier to code
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                //a moment wil come when it will complete scan the whole matrix and wont find any empty cell then it will hit the base case which returns true, written at the end of function
                if(board[row][col] == '.'){ 
                    for(char num = '1'; num <= '9'; num++){
                        if(isValid(row, col, num, board)){
                            board[row][col] = num;
                            if(solve(board)) return true; 
                        //whenever it calls it starts scanning again from the (0,0) cell for the empty cell

                        //if valid combination occurs then percolate true upwards till the top;
                            else board[row][col] = '.';
                        }
                    }
                    //if all 9 fails then retyrn false, as one of them need to be valid
                    return false;
                }
            }
        }
        return true; //all cells traversed 
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans;
        if(solve(board)) return;
    }
};