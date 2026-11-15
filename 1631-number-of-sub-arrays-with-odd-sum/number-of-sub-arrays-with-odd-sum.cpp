class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int M = 1e9 + 7;
        int n = arr.size();
        long long even = 1;
        long long odd = 0;

        vector <long long> prefix(n);
        prefix[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        long long count = 0;
        for(int i = 0; i < n; i++){
            if(prefix[i] % 2 == 0){
                count = (count + odd)%M;
                even++;
            }
            else{
                count = (count + even)%M;
                odd++;
            }
        }

        return count;
    }
};