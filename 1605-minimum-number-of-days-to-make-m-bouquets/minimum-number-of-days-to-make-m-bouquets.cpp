class Solution {
    bool check(int day, int m, int k, vector<int>& bloomDay){
        int cnt = 0;
        int b = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day) cnt++;
            else{
                b += cnt/k;
                cnt = 0;
            }
        }
        b += cnt/k; //As if last indices are adj with bloomed flowers it wont be counted

        return m <= b;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m > n/k) return -1;

        int low = 1e9 + 1;
        int high = 0;
        for(int i = 0; i < n; i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(mid, m, k, bloomDay)) high = mid-1;
            else low = mid+1;
        }

        return low;
    }
};