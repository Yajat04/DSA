class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = num;
        for(int i = 1; i <= num/2; i++) if(num % i == 0) sum -= i;
        return sum == 0;
    }
};