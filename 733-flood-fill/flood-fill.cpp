class Solution {
    void dfs(int m, int n, int* dx, int* dy, vector<vector<int>>& image, int sr, int sc, 
                int &color, int &orgColor, vector<vector<int>> &ans){
        ans[sr][sc] = color;
        for(int i = 0; i < 4; i++){
            int nrow = sr + dx[i];
            int ncol = sc + dy[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && ans[nrow][ncol] != color && image[nrow][ncol] == orgColor){
                dfs(m, n, dx, dy, image, nrow, ncol, color, orgColor, ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if(orgColor == color) return image;

        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans(m, vector <int> (n, -1)); 
        //As updation to org vector is bad practice

        //vector<vector<bool>> vis(m , vector <bool> (n)); 
        //No need as we can track using ans vector

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        dfs(m, n, dx, dy, image, sr, sc, color, orgColor, ans);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ans[i][j] == -1) ans[i][j] = image[i][j];
            }
        }

        return ans;
    }
};