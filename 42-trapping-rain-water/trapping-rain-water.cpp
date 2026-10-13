class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int tot = 0;

        int leftmax = height[left];
        int rightmax = height[right];
        while(left < right){
            if(height[left] <= height[right]){
                if(leftmax > height[left]) tot += leftmax - height[left];
                else leftmax = height[left];
                left++;
            }

            else{
                if(rightmax > height[right]) tot += rightmax - height[right];
                else rightmax = height[right];
                right--;
            }
        }

        return tot;
    }
};