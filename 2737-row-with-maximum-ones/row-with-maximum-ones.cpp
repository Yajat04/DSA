class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_cnt = -1;
        int idx = -1;
        int m = mat.size();
        int n = mat[0].size();
        for(int i = 0; i < m; i++){
            int cnt = 0;

            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1)
                    cnt++;
            }

            /* If all rows sorted in asc order
            int lb = lower_bound(mat[i].begin(), mat[i].end(), 1) - mat[i].begin();
            cnt = n - lb;
            */

            if(cnt > max_cnt){
                max_cnt = cnt;
                idx = i;
            }
            
        }

        return {idx, max_cnt};
    }
};