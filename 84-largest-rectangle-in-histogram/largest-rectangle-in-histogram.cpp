class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int n = heights.size();
        int maxi = -1;
        int nse, pse;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int top = st.top();
                st.pop();

                if(st.empty()) pse = -1;
                else pse = st.top();
                nse = i;

                int area = heights[top] * (nse - pse - 1);
                if(maxi < area) maxi = area;
            }
            st.push(i);
        }

        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(st.empty()) pse = -1;
            else pse = st.top();
            nse = n;

            int area = heights[top] * (nse - pse - 1);
            if(maxi < area) maxi = area;
        }

        return maxi;
    }
};