class Solution {
public:
    int maxProduct(int n){
        int maxi = 0;
        string s = to_string(n);
        int left = 0;

        while(left != s.size()){
            for(int right = left + 1; right < s.size(); right++){
                int r = s[right] - '0';
                int l = s[left] - '0';
                maxi = max(maxi, r * l);    
            }
            left++;
        }

        return maxi;
        
    }
};