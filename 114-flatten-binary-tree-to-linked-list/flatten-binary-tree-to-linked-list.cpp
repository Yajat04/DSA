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
    void compute_preorder(TreeNode* root, vector<TreeNode*> &preorder){
        if(!root) return;

        preorder.push_back(root);
        compute_preorder(root-> left, preorder);
        compute_preorder(root-> right, preorder);
    }
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> preorder;

        compute_preorder(root, preorder);
        int n = preorder.size();

        for(int i = 0; i < n; i++){
            preorder[i] -> left = NULL;
            if(i != n-1) preorder[i] -> right = preorder[i+1];
        }
  }
};