class Solution {
    int MOD = 1e9 + 7;
    void make_nse_pse(vector<int> &pse, vector<int> &nse, vector<int>& arr){
        int n = arr.size();
        stack<int> s1;
        stack<int> s2;

        for(int i = n-1; i >= 0; i--){
            while(!s1.empty() && arr[s1.top()] >= arr[i]) s1.pop();
            nse[i] = s1.empty() ? n : s1.top();
            s1.push(i);
        }

        for(int i = 0; i < n; i++){
            while(!s2.empty() && arr[s2.top()] > arr[i]) s2.pop();
            pse[i] = s2.empty() ? -1 : s2.top();
            s2.push(i);
        }
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse(n);
        vector<int> pse(n);

        make_nse_pse(pse, nse, arr);

        long long tot = 0;
        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;

            tot = (tot + (left * right * (1LL * arr[i]))%MOD)%MOD;
        }

        return tot;
    }
};