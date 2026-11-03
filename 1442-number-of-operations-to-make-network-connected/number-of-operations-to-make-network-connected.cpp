class Solution {
    int findParent(int u, vector <int> &parent){
        while(parent[u] != u){
            u = parent[u];
        }
        return u;
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector <int> parent(n, -1);
        vector <int> rank(n, -1);
        int count = 0;

        for(int i = 0; i < n; i++) parent[i] = i;
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if(pv == pu) count++;
            else{
                if(rank[pu] == rank[pv]){
                rank[pu]++;
                parent[pv] = pu;
                }
                else if(rank[pu] > rank[pv]) parent[pv] = pu;
                else parent[pu] = pv;
            }
        }

        set <int> st;
        for(int i = 0; i < n; i++){
            int pi = findParent(i, parent);
            if(st.count(pi) > 0) continue;
            st.insert(pi);
        }

        if(count < st.size()-1) return -1;
        return st.size()-1;

    }
};