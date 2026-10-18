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
    TreeNode* build(int postStart, int postEnd, int inStart, int inEnd, 
                    vector<int>& postorder, vector<int>& inorder, unordered_map < int, int > &inMap){
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root -> val];
        int numsLeft = inRoot - inStart;

        root -> left = build(postStart, postStart + numsLeft - 1, inStart, inRoot-1, postorder, inorder, inMap); 
        root -> right = build(postStart + numsLeft, postEnd-1, inRoot + 1, inEnd, postorder, inorder, inMap); 

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map < int, int > inMap;

        int postSize = postorder.size();
        int inSize = inorder.size();

        for(int i = 0; i < inSize; i++) inMap[inorder[i]] = i;

        TreeNode* root = build(0, postSize-1, 0, inSize-1, postorder, inorder, inMap);
        return root;
    }
};