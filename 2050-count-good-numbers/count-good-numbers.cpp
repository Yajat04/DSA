class Solution {
    //Combinations
    //use and solve all in long long, while update use mod
    //at the end, last moment convert to int, mod ensures to keep result in range of int

    const int mod = 1e9 + 7;
    long long power(long long x, long long n){
        long long ans = 1;

        while(n > 0){
            if(n%2 == 1) {
                ans = (ans * x)%mod;
                n = n-1;
            }

            else {
                x = (x * x)%mod;
                n = n/2;
            }
        }

        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long odd_idx;
        long long even_idx;
        if(n%2 == 1) {
            odd_idx = n/2;
            even_idx = n/2 + 1;
        }
        else odd_idx = even_idx = n/2;

        long long even_ways = power(5, even_idx);
        long long odd_ways = power(4, odd_idx);
        return (even_ways * odd_ways)%mod; 
    }
};