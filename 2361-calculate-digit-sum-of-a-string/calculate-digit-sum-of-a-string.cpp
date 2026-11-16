class Solution {
    string digSum(string s, int low, int high){
        int sum = 0;
        for(int i = low; i < high; i++){
            sum += int(s[i] - '0');
        }

        return to_string(sum);
    }
public:
    string digitSum(string s, int k) {
        int n = s.size();
        if(n < k) return s;

        string ans  = s;
        while(ans.size() > k){
            string newStr = "";
            int t = 0;
            while(t < ans.size()){
                if(t + k > ans.size()){
                    newStr += digSum(ans, t, ans.size());
                    break;
                }
                newStr += digSum(ans, t, t+k);
                t += k;
            }
            ans = newStr;
        }

        return ans;
    }
};