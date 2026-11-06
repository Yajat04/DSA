class Solution {
    // Is it a contiguous range query -> Yes, [Q - x, Q]
    // Can we sort queries to make boundaries move in one direction -> Yes, both Q - x and Q move right monotonically, means the next range is of higher order and hence the right (moving fwd) correctly checks for higher time logs
    // Is updating state O(1) when adding/removing one element -> Yes, updating frequency count and activeServers count
    // Pattern -> Sliding Window
    // Intuiton -> dont repeatedly check for same servers in the common query ranges, hold the servers that are common b/w consecutive queries, and move monotonically both ways by dropping the done servers

    // Why map instead of set?? as on removal (while left move) set would completely delete the el but if the window still holds that server then it would be wrong hence count rep it correctly

    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        sort(logs.begin(), logs.end(), compare);

        vector <vector<int>> sortQueries;
        for(int i = 0; i < queries.size(); i++) sortQueries.push_back({i, queries[i]});
        sort(sortQueries.begin(), sortQueries.end(), compare);

        int left = 0;
        int right = 0;
        unordered_map <int, int> serverCount;
        vector <int> ans(queries.size());
        for(int i = 0; i < sortQueries.size(); i++){
            int idx = sortQueries[i][0];
            int q = sortQueries[i][1];

            int low = q - x;
            int high = q;

            while(right < m && logs[right][1] <= high){
                int id = logs[right][0];
                serverCount[id]++;
                right++;
            }

            while(left < m && logs[left][1] < low){
                int id = logs[left][0];
                serverCount[id]--;
                if(serverCount[id] == 0) serverCount.erase(id);
                left++;
            }

            ans[idx] = n - serverCount.size();
        }

        return ans;
    }
};