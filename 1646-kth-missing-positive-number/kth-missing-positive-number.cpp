class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = arr[0] - 1;
        if(cnt >= k) return k;

        for(int i = 1; i < n; i++){
            cnt += arr[i] - arr[i-1] - 1;
            if(cnt >= k){
                int last = arr[i-1];
                int prevcnt = cnt -(arr[i] - arr[i-1] - 1);
                return last + k - prevcnt;
            }
        }
        
        return arr[n-1] + k - cnt;
    }
};