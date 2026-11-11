class Solution {
    static bool compare(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> ans;
        int low = intervals[0][0];
        int high = intervals[0][1];

        int left = 0;
        for(int right = 1; right < n; right++){
            if(intervals[right][0] > high){
                ans.push_back({low, high});
                left = right;
                low = intervals[right][0];
                high = intervals[right][1];
            }   
            else high = max(high, intervals[right][1]);
        }

        ans.push_back({low, high});
        return ans;
    }
};