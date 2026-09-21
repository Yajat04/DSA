class Solution {
    //Something like testing capacities from 1 to x
    //there will be a capacity(minCap) which will result in possible transfer
    //therfore not poss -> poss
    //hence think of BS

    bool check(int cap, vector<int>& weights, int days){
        int cnt = 0;
        int sum = 0;

        int n = weights.size();
        for(int i = 0; i < n; i++){
            if(weights[i] > cap) return false;
            if(sum + weights[i] <= cap){
                sum += weights[i];
            }
            else{
                cnt++;
                sum = weights[i];
            }
        }

        cnt++;
        return cnt <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;

        for(int wt : weights){
            low = max(low, wt);
            high += wt;
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, weights, days)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};