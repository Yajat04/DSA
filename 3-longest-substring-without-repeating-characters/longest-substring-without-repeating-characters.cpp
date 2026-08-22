class Solution {
    //substring, as it wpuld require some bracket containing continous chars
    //reminds of window
    //dynamic window as we need to find largest of the substring
    //move left ahead upto that point such that freq of the repeating el resets to 1
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        vector <int> last(128, -1);
        int maxi = 0;
        for(int right = 0; right < s.size(); right++){
            if(last[s[right]] >= left) left = last[s[right]] + 1;
            last[s[right]] = right;

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};