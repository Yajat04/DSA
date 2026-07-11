class Solution {
    void dfs(int node, unordered_map <int, bool> &vis, vector<vector<int>>& isConnected){
        vis[node] = true;

        for(int j = 0; j < isConnected[0].size(); j++){
            if(isConnected[node][j]){
                if(!vis[j]) dfs(j, vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province = 0;
        unordered_map <int, bool> vis;
        
        for(int i = 0; i < isConnected[0].size(); i++){
            if(!vis[i]){
                dfs(i, vis, isConnected);
                province++;
            }
        }
        return province;
    }
};