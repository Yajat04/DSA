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
    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd, 
                    vector<int>& preorder, vector<int>& inorder, unordered_map < int, int > &inMap){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root -> val];
        int numsLeft = inRoot - inStart;

        root -> left = build(preStart + 1, preStart + numsLeft, inStart, inRoot-1, preorder, inorder, inMap); 
        root -> right = build(preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd, preorder, inorder, inMap); 

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map < int, int > inMap;

        int preSize = preorder.size();
        int inSize = inorder.size();

        for(int i = 0; i < inSize; i++) inMap[inorder[i]] = i;

        TreeNode* root = build(0, preSize-1, 0, inSize-1, preorder, inorder, inMap);
        return root;
    }
};