class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <pair <int, int>> adj[n]; //array of vector of pairs, to make adj list
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector <long long> dist(n, LLONG_MAX);
        dist[src] = 0;

        queue < pair <int , pair < long long, int >>> q;
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            int stops = front.first;
            int node = front.second.first;
            int cost = front.second.second;

            if(stops > k) continue;

            for(auto nbr : adj[node]){
                if(nbr.second + cost < dist[nbr.first] && stops <= k){
                    dist[nbr.first] = cost + nbr.second;
                    q.push({stops + 1, {nbr.first, dist[nbr.first]}});
                }
            }
        }


        if(dist[dst] == LLONG_MAX) return -1;
        return dist[dst];

        
    }
};