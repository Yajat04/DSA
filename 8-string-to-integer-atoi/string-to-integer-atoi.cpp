class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces, spces aint present in b/w, only leading if present
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle empty string after spaces
        if (i == n) return 0;

        // Check sign, this clause ignored if no sign indicative and following 'pos'
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        int num = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow
            if(num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)){
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
                //for intmin the dig = 8 which is indeed > 7, therefre the same clause works for it, 
                //till 7 it is handled, if it is 8 and sign - then also intmin is to be returned
                //and > 8 also intmin for sign -, therefore same condition remains valid
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};