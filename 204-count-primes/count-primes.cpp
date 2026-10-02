class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        int m = n / 2;
        vector<bool> flag(m, true);

        for(int p = 3; p*p < n; p += 2){
            if(flag[p / 2]){
                for(int q = p*p; q < n; q += 2*p){
                    flag[q / 2] = false;
                }
            }
        }

        int cnt = 1;

        for(int i = 1; i < m; i++){
            if(flag[i]) cnt++;
        }

        return cnt;
    }
};