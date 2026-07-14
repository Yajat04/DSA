class Solution {
    void make_adj(vector<vector<int>>& times, unordered_map <int, 
                list <pair <int, int>>> &adj){
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map <int, list <pair <int, int>>> adj;
        vector<int> dist(n + 1, 1e3);
        dist[0] = -1;
        dist[k] = 0;
        make_adj(times, adj);

        set <pair <int, int>> s;
        s.insert({0, k});

        while(!s.empty()){
            auto front = *s.begin();
            s.erase(s.begin());

            for(auto neighbour : adj[front.second]){
                if(front.first + neighbour.second < dist[neighbour.first]){
                    auto old = s.find({dist[neighbour.first] , neighbour.first});
                    if(old != s.end()){
                        s.erase(old);
                    }
                    dist[neighbour.first] = front.first + neighbour.second;
                    s.insert({dist[neighbour.first], neighbour.first});
                }
            }
            
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e3) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;

    }
};