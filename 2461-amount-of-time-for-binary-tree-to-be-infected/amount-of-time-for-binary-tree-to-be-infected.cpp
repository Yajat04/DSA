/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

    TreeNode* findTarget(TreeNode* root, int &tar){
        if(!root) return NULL;
        if(root -> val == tar) return root;

        TreeNode* left = findTarget(root -> left, tar);
        TreeNode* right = findTarget(root -> right, tar);

        if(left != NULL) return left;
        return right;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
        unordered_map <TreeNode*, TreeNode*> parent;
        prepare_parent(root, parent);

        unordered_map <TreeNode*, bool> vis;
        queue <TreeNode*> q;
        vector<int> ans;

        TreeNode* target = findTarget(root, start);
        q.push(target);
        vis[target] = true;

        int time = 0;
        while(!q.empty()){
            time++; //Increase timestamp

            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(parent[node] && !vis[parent[node]]){ //Up
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }

                if(node -> left && !vis[node -> left]){ //Left
                    q.push(node -> left);
                    vis[node -> left] = true;
                }

                if(node -> right && !vis[node -> right]){ //Right
                    q.push(node -> right);
                    vis[node -> right] = true;
                }
            }
        }

        return time-1;
    }
};