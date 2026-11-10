class Solution {
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n <= 1) return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int count = 0;

        int left = 0;
        for(int right = 1; right < n; right++){
            int dright = intervals[right][1] - intervals[right][0];
            int dleft = intervals[left][1] - intervals[left][0];

            if(intervals[right][0] < intervals[left][1]){
                if(intervals[right][1] < intervals[left][1]) left = right; 
                count++;
            }
            else left = right;
        }

        return count;
    }
};