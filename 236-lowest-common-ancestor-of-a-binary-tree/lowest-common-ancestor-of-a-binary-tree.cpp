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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base cases: empty tree or found p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Recurse on left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right return non-null, root is the LCA
        if (left != nullptr && right != nullptr) {
            return root;
        }

        // Otherwise, return whichever subtree found p or q
        return (left != nullptr) ? left : right;
    }
};