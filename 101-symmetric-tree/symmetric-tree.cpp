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
    bool isMirror(TreeNode* rootA, TreeNode* rootB){
        if(rootA == NULL || rootB == NULL) return rootA == rootB;
        if(rootA -> val != rootB -> val) return false;

        return isMirror(rootA -> left, rootB -> right) && isMirror(rootA -> right, rootB -> left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return (root == NULL || isMirror(root -> left, root -> right));
        
    }
};