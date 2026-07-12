class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        vector <int> last(128, -1); //s consists of English letters, digits, symbols and spaces, if only lowercase letters then 26 would have been enough
        int maxi = 0;
        for(int right = 0; right < s.size(); right++){
            if(last[s[right]] >= left) left = last[s[right]] + 1;
            last[s[right]] = right;

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};