class Solution {
    void make_adj(vector<vector<int>>& edges, unordered_map <int, vector<pair<int, int>>>& adjlist){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adjlist[u].push_back({v, w});
            adjlist[v].push_back({u, w});
        }
    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        priority_queue <pair<int,  int>, vector<pair<int,  int>>, greater<pair<int,  int>>> pq;
        unordered_map <int, vector<pair<int, int>>> adjlist;
        make_adj(edges, adjlist);
        vector <int> cityCount(n, 0);

        for(int i = 0; i < n; i++){
            vector <int> dist(n, INT_MAX);
            dist[i] = 0;
            pq.push({0, i});

            while(!pq.empty()){
                auto [d, n] = pq.top();
                pq.pop();

                if(d > dist[n]) continue;
                if(d <= distanceThreshold) cityCount[i]++;
                
                for(auto &nbr : adjlist[n]){
                    auto [v, w] = nbr;
                    if(w + d < dist[v]){
                        dist[v] = w + d;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
        
        int mini = INT_MAX;
        int idx = 0;
        for(int i = 0; i < n; i++){
            if(cityCount[i] <= mini){
                mini = cityCount[i];
                idx = i;
            }
        }

        return idx;
        


    }
};