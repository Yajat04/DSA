class Solution {
    int n;
    bool canPlace(int minDis, vector<int>& position, int &m){
        int cowplaced = 1;
        int lastplaced = 0;
        for(int i = 1; i<n; i++){
            if(position[i]-position[lastplaced] >= minDis){
                cowplaced++;
                lastplaced = i;
            }
        }

        return cowplaced >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        n = position.size();
        int low = 1;
        int high = position[n-1] - position[0];

        while(low <= high){
            int mid = low + (high-low)/2;
            if(canPlace(mid, position, m)) low = mid + 1;
            else high = mid-1;
        }
        return high;
    }
};