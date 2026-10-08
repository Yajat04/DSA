class Solution {
    void dictionary(unordered_map <char, string> &mp){
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }

    void solve(int i, string &digits, string &temp, vector<string> &ans, 
                unordered_map <char, string> &mp){
        if(i == digits.size()){
            ans.push_back(temp);
            return;
        }

        string curr = mp[digits[i]];
        for(int j = 0; j < curr.size(); j++){
            temp += curr[j];
            solve(i+1, digits, temp, ans, mp);
            temp.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        string temp = "";
        vector<string> ans;

        unordered_map <char, string> mp;
        dictionary(mp);

        solve(0, digits, temp, ans, mp);
        return ans;

    }
};