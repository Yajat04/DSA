class Solution {
    bool checkPalindrome(string s){
        int low = 0;
        int high = s.size()-1;

        while(low < high) if(s[low++] != s[high--]) return false;

        return true;
    }

    void PalindromePartition(int i, string &s, vector<string> &res, vector<vector<string>> &ans){
        if(i == s.size()){
            ans.push_back(res);
            return;
        }

        string temp = "";
        for(int idx = i; idx < s.size(); idx++){
            temp += s[idx];
            if(checkPalindrome(temp)){
                res.push_back(temp);
                PalindromePartition(idx+1, s, res, ans);
                res.pop_back();
            }
        } 
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> res;

        PalindromePartition(0, s, res, ans);

        return ans;
    }
};