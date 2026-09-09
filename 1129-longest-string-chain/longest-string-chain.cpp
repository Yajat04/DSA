class Solution {
    bool compare(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;
        int fir = 0;
        int sec = 0;
        while(fir < s1.size()){
            if(sec < s2.size() && s1[fir] == s2[sec]){
                fir++;
                sec++;
            }
            else fir++;
        }

        if(fir == s1.size() && sec == s2.size()) return true;
        return false;
    }

public:
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);

        sort(words.begin(), words.end(), comp);

        int maxi = -1;
        for(int i = 0; i < n; i++){
            for(int pi = 0; pi < i; pi++){
                if(compare(words[i], words[pi]) && dp[i] < 1 + dp[pi]){
                    dp[i] = 1 + dp[pi];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};