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
    //M1: Findout inorder traversal and
        //sort it 
        //then do the traversal again and change the node value with the sorted array values if the values dont match
        //Need to traverse the whole tree again as we dont know about the nodes until we reach them

    //M2: No need of storing the inorder traversal we just require the nodes whihc need to be swapped no requirement on checing the whole tree again 
        //Violation can occur in two ways:
        //Case 1: When non adj nodes need to be swapped (assumed in the inorder traversal) => Two Flags(first,last)
        //Case 2: When adj nodes need to be swapped (assumed in the inorder traversal) => one flag(first, middle)
        TreeNode* prev;
        TreeNode* first;
        TreeNode* middle;
        TreeNode* last;
public:
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);

        //When reach the node, compare it with the previous to know the violation
        if(prev != NULL && prev->val > root-> val){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else last = root;
        }

        prev = root;
        inOrder(root -> right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = prev = NULL;
        inOrder(root);
        
        if(first && last) swap(first->val, last-> val);
        else swap(first->val, middle->val);
    }
};