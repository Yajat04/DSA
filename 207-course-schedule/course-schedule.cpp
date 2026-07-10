class Solution {
    void make_adj(unordered_map <int, list <int> > &adj, vector<vector<int>>& prerequisites){
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }
    }

    bool detectCycle(int node, unordered_map <int, list <int> > &adj, 
                unordered_map <int, bool> &dfs, unordered_map <int, bool> &vis){
        vis[node] = true;
        dfs[node] = true;

        for(auto neighbor : adj[node]){
            if(!vis[neighbor]){
                bool detect = detectCycle(neighbor, adj, dfs, vis);
                if(detect) return true;
            }

            else if(dfs[neighbor] == 1) return true; //Once this executes it will retuen true till top
        }

        dfs[node] = false; //if the path is completed and no more nodes aree present then only it will execute
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> allNodes;
        for(int i = 0; i < numCourses; i++) allNodes.push_back(i);
        unordered_map <int, bool> dfs;
        unordered_map <int, bool> vis;
        unordered_map <int, list <int> > adj;
        make_adj(adj, prerequisites);


        for(auto node : allNodes){
            if(!vis[node]){
                bool detect = detectCycle(node, adj, dfs, vis);
                if(detect) return false;
            }
        }

        return true;
    }
};