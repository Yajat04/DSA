class Solution {
    void make_adj(vector<vector<int>>& roads, unordered_map <int, 
                list <pair <int, int>>> &adj){
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
    }
public:
    int countPaths(int n, vector<vector<int>>& roads){
        unordered_map <int, list <pair <int, int>>> adj;
        make_adj(roads, adj);

        priority_queue < pair < long long, int > ,
                            vector < pair < long long, int > > ,
                            greater < pair < long long, int > >
                        > pq;
        vector < long long > dist (n, LLONG_MAX);
        vector < int > ways (n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        int mod = (int)(1e9 + 7);

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            long long t =  top.first;
            int node =  top.second;

            if(dist[node] < t) continue;

            for(auto nbr : adj[node]){

                //The first time it reaches the node with min dist
                if(t + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = t + nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                    ways[nbr.first] = ways[node]; //No need of modula herre as the ways[node] is already maintained modulo                
                }

                //The rest of the time it reaches the node with min dist
                else if(t + nbr.second == dist[nbr.first]){
                    ways[nbr.first] = (ways[nbr.first] + ways[node])%mod;
                }
            }
        }

        return ways[n-1];
    }
};