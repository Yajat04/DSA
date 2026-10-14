class Solution {
    int solve(vector<int> &heights){
        int n = heights.size();
        stack <int> st;
        int pse, nse;

        int max_rect = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int top = st.top();
                st.pop();

                nse = i;
                if(st.empty()) pse = -1;
                else pse = st.top();

                max_rect = max(max_rect, heights[top] * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int top = st.top();
            st.pop();

            nse = n;
            if(st.empty()) pse = -1;
            else pse = st.top();

            max_rect = max(max_rect, heights[top] * (nse - pse - 1));
        }

        return max_rect;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> heights(n, 0);
        int maximal = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maximal = max(maximal, solve(heights));
        }

        return maximal;
    }
};