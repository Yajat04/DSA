class Solution {
    void dfs(int u, int parent, int &timer, vector <int> &arrive, vector <int> &last, 
            unordered_map <int, list<int>> &adj, vector<vector<int>> &ans){
        arrive[u] = last[u] = timer++;
        for(int nbr : adj[u]){
            if(nbr == parent) continue; //Dont traaverse that edge which it came from parent
            if(arrive[nbr] == -1){
                dfs(nbr, u, timer, arrive, last, adj, ans);
                if(last[nbr] > arrive[u]) ans.push_back({u, nbr});
                last[u] = min(last[u], last[nbr]);
            }

            else last[u] = min(last[u], arrive[nbr]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        vector <int> arrive(n, -1);
        vector <int> last(n, -1);

        unordered_map <int, list<int>> adj;
        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> ans;
        int timer = -1; // Causes error i we directly put -1 as timer is used as reference
        //Hence variable is to be passed
        dfs(0, -1, timer, arrive, last, adj, ans);
        return ans;

    }
};