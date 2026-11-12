class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector <int> arrival;
        vector <int> departure;

        for (int i = 0; i < intervals.size(); i++) {
            arrival.push_back(intervals[i][0]);
            departure.push_back(intervals[i][1]);
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int a = 0;
        int d = 0;

        int cnt = 0;
        int maxCnt = 0;
        while(a < arrival.size() && d < departure.size()){
            if(arrival[a] <= departure[d]){
                a++;
                cnt++;
            }
            else{
                d++;
                cnt--;
            }
            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }
};