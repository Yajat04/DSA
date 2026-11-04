class disjointSetUnion{
    public: 
    vector <int> parent, size; //here size is the number of nodes in the group(ie under root) not number of emails
    disjointSetUnion(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i < n+1; i++) parent[i] = i;
    }

    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } 
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disjointSetUnion ds(n); 
        //0 to n-1 nodes created for each of the n entries

        unordered_map <string, int> mailMapNode;
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailMapNode.count(mail) == 0) mailMapNode[mail] = i;
                else ds.unionBySize(mailMapNode[mail], i); 
            }
        }
        //uptill now the mails ain't merged we just letting know the class ds that what nodes are merged
        //parent - child relation established uptill now

        vector<string> merged[n];
        for(auto &it : mailMapNode){
            auto mail = it.first;
            auto Node = it.second;

            int pNode = ds.findParent(Node); 
            merged[pNode].push_back(mail); //Directly assigning at the root node
        } //here mails are merged

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){ //Go through each node
            if(merged[i].size() == 0) continue; //Those node which are merged as a child won't have any entries

            vector <string> res;
            res.push_back(accounts[i][0]); //since the common acc will have the same name so the root of the merger will be either of the account entry and originally they are linked to original entries hence pick the name from there
            sort(merged[i].begin(), merged[i].end());
            for(auto &mail: merged[i]) res.push_back(mail);

            ans.push_back(res);
        }

        return ans;
    }
};