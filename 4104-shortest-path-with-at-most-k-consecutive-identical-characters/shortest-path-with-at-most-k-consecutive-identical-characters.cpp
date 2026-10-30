class Solution {
    void make_adj(vector<vector<int>>& edges, unordered_map<int, vector<pair<int, int>>> &adjlist){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adjlist[u].push_back({v,w});
        }
    }
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int, vector<pair<int, int>>> adjlist;
        make_adj(edges, adjlist);
        priority_queue<pair<pair<long long,int>, int>, vector<pair<pair<long long,int>, int>>, 
                        greater<pair<pair<long long,int>, int>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX)); //dist may be large
        //Must contain the frequency as well,
        // as there may be two or more paths reaching same node, Ex
        // two valid dist for two valid frequencies for any intermediate node but if that dist is smaller for a freq which may become invalid then the other freq, dist must be preserved to be used later

        pq.push({{0,1}, 0});
        dist[0][1] = 0;
        
        while(!pq.empty()){
            auto [p, u] = pq.top();
            auto [d, f] = p;
            pq.pop();

            if(d > dist[u][f]) continue;
            if(u == n-1) return d;

            for(auto &nbr: adjlist[u]){
                int v = nbr.first;
                int w = nbr.second;

                int nf = (labels[u] == labels[v]) ? f + 1 : 1;

                if(nf > k) continue;

                if(d + w < dist[v][nf]){
                    dist[v][nf] = d + w;
                    pq.push({{d + w, nf}, v});
                }
            }
        }

        return -1;
    }
};