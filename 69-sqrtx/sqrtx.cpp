class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int low = 1;
        int high = x/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            long long sq = 1LL * mid * mid;
            if(sq > x) high = mid - 1;
            else if(sq == x) return mid;
            else low = mid+1; 
        }

        return high;
    }
};