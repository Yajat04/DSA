/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void prepare_parent(TreeNode* root, unordered_map <TreeNode*, TreeNode*> &parent){
        queue <TreeNode*> q;

        parent[root] = root;
        q.push(root);
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();

                if(node ->  left){
                    q.push(node -> left);
                    parent[node -> left] = node;
                }

                if(node ->  right){
                    q.push(node -> right);
                    parent[node -> right] = node;
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        unordered_map <TreeNode*, TreeNode*> parent;
        prepare_parent(root, parent);

        unordered_map <TreeNode*, bool> vis;
        queue <TreeNode*> q;
        vector<int> ans;

        q.push(target);
        vis[target] = true;

        int dist = 0;
        while(!q.empty()){
            if(dist++ == k) break;

            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }

                if(node -> left && !vis[node -> left]){
                    q.push(node -> left);
                    vis[node -> left] = true;
                }

                if(node -> right && !vis[node -> right]){
                    q.push(node -> right);
                    vis[node -> right] = true;
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front() -> val);
            q.pop();
        }

        return ans;

    }
};