class Solution {
    int findParent(int u, vector <int> &parent){
        while(parent[u] != u){
            u = parent[u];
        }
        return u;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        vector <int> parent(n, -1);
        vector <int> rank(n, -1);
        int components = n;

        for(int i = 0; i < n; i++) parent[i] = i;
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            int pu = findParent(u, parent);
            parent[u] = pu;
            int pv = findParent(v, parent);
            parent[v] = pv;

            if(pv != pu){
                if(rank[pu] == rank[pv]){
                rank[pu]++;
                parent[pv] = pu;
                }
                else if(rank[pu] > rank[pv]) parent[pv] = pu;
                else parent[pu] = pv;
                components--;
            }
        }

        return components-1;

    }
};