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
    void preorder(TreeNode* root, map <int, int> &ksmallest){
        if(root == NULL) return;

        ksmallest[root -> val] += 1;
        preorder(root -> left, ksmallest);
        preorder(root -> right, ksmallest);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        map <int, int> ksmallest;
        preorder(root, ksmallest);
        auto it = next(ksmallest.begin(), k-1);
        return it->first;
    }
};