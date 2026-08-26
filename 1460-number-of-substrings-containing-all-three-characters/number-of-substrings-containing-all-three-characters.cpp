class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        int right = 0;
        int left = 0;
        int cnt = 0;

        vector <int> hash(3, -1);
        for(int right = 0; right < n; right++){
            hash[s[right] - 'a'] = right;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                cnt += 1 + min(hash[0], min(hash[1], hash[2]));
            }
        }

        return cnt;
        
    }
};