class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        int m = heights.size();
        long long ans = 0;

        for(int peak = 0; peak < m; peak++){
            long long sum = heights[peak];

            //left
            int mini_left = heights[peak];
            for(int left = peak - 1; left >= 0; left--){
                mini_left = min(heights[left], mini_left);
                sum += mini_left;
            }

            //right
            int mini_right = heights[peak];
            for(int right = peak+1; right < m; right++){
                mini_right = min(heights[right], mini_right);
                sum += mini_right;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};