class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> rightmax(n, -1);
        vector<int> leftmax(n, -1);

        int left = height[0];
        for(int i=0; i < n; i++){
            leftmax[i] = max(left, height[i]);
            if(left < height[i]) left = height[i];
        }

        int right = height[n-1];
        for(int i=n-1; i >= 0; i--){
            rightmax[i] = max(right, height[i]);
            if(right < height[i]) right = height[i];
        }

        int units = 0;
        for(int i = 0; i < n; i++){
            units += abs(min(leftmax[i], rightmax[i]) - height[i]);
        }

        return units;
    }
};