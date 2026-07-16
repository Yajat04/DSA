class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        //trusts a -> b, a trusts b
        vector <pair<int, int>> freq(n+1, {0, 0});

        for(int i = 0; i < trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];

            freq[b].first++;
            freq[a].second++;
        }

        for(int i = 1; i <= n; i++){
            if(freq[i].first == n-1 && freq[i].second == 0) return i;
        }

        return -1;
    }
};