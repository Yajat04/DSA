class Solution {
    bool bfs(int src, vector <int> &isColored, vector<vector<int>>& graph){
        //color 0 and 1
        queue <int> q;
        q.push(src);
        isColored[src] = 0; //can give either color to starting node

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto nbr : graph[front]){
                if(isColored[nbr] == -1){
                    if(isColored[front] == 1) isColored[nbr] = 0;
                    else isColored[nbr] = 1;

                    q.push(nbr);
                } 

                else if(isColored[front] == isColored[nbr]) return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector <int> isColored(n, -1);

        for(int i = 0; i < n; i++){
            if(isColored[i] == -1){
                bool ans = bfs(i, isColored, graph);
                if(!ans) return false;
            }
        }

        return true;

    }
};