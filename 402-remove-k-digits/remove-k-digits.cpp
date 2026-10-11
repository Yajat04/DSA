class Solution {
public:
    string removeKdigits(string num, int k) {
        stack <char> st;
        int n = num.size();

        if(n == k) return "0";

        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() > num[i] &&  i < st.size() + k) st.pop();
            if(st.size() < n-k) st.push(num[i]);
        }

        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        for(int i = ans.size()-1; i > 0; i--){
            if(ans[i] == '0') ans.pop_back();
            else break;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};