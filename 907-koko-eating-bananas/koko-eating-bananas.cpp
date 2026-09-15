class Solution {
    bool check(int k, int h, vector<int>& piles){
        long long hr = 0;
        for(int i = 0; i < piles.size(); i++){
            hr += (piles[i] + k - 1) / k;
        }
        return hr <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        int n = piles.size();
        for(int i = 0; i < n; i++) high = max(high, piles[i]);

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, h, piles)) high = mid -1;
            else low = mid + 1;
        }

        return low;
    }
};