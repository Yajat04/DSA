class Solution {
    void make_adj(unordered_map <int, list <int> > &adj, unordered_map <int, int> &inDeg,vector<vector<int>>& prerequisites){
        for(auto edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            inDeg[edge[0]]++; 
        }
    }

    void detectCycle(int n, unordered_map <int, list <int> > &adj, unordered_map <int, int> &  inDeg, vector <int> &ans){
        
        queue <int> q;
        for (int i = 0; i < n; i++) {
            if(inDeg[i] == 0) q.push(i); //Handles disconnected components here only, no separate check
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto neighbor : adj[front]){
                inDeg[neighbor]--;
                if(inDeg[neighbor] == 0) q.push(neighbor);
            }
        }
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> ans; 
        unordered_map <int, int> inDeg;
        unordered_map <int, list <int> > adj;
        make_adj(adj, inDeg, prerequisites);

        detectCycle(numCourses, adj, inDeg, ans);

        if(ans.size() != numCourses) ans.clear();

        return ans;
    }
};