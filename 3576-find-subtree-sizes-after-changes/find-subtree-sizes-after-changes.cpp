class Solution { 
    //when there is multichild tree, solve it as directed graph (prepare adj list of parent -> children)
    //use recursion (dfs) to solve tree problems
    //here instead of looking back to parent perform dfs from the start(order as per order of children stored in the adj list)
    //keep updating "last scene" for the alphabets discovered till the current stage it would be equivalent to nearest ancestor to current node and character

    void dfs(int i, vector<int>& parent, string &s, unordered_map <int, vector<int>> &adj, vector <int> &last, vector <int> &ans){
        int lastAnscestor = last[s[i] - 'a'];
        last[s[i] - 'a'] = i;

        for(auto &child: adj[i]){
            dfs(child, parent, s, adj, last, ans);
        }

        last[s[i] - 'a'] = lastAnscestor;
        if(i != 0){
            if(lastAnscestor != -1)
                parent[i] = lastAnscestor;

            ans[parent[i]] += ans[i];
        }
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map <int, vector<int>> adj; //direct children (nbr)
        vector <int> last(26, -1);
        last[s[0] - 'a'] = 0;

        for(int i = 1; i < n; i++){
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }

        // to restructure the tree
        vector <int> ans(n, 1);
        dfs(0, parent, s, adj, last, ans);
        return ans;
    }
};