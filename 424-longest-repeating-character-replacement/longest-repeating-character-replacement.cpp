class Solution {
    //Substring buddy
    //same char present in bracket
    //hence sliding window
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        
        vector <int> hash(26, 0);
        int maxLen = 0;
        int maxf = 0;
        for(int right = 0; right < n; right++){
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);
            if((right - left + 1) - maxf > k) hash[s[left++] - 'A']--;
            if((right - left + 1) - maxf <= k) maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};