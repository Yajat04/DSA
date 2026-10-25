/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class NodeValue {
public:
    int minNode;
    int maxNode;
    int sum;

    NodeValue(int mini, int maxi, int sum) {
        minNode = mini;
        maxNode = maxi;
        this-> sum = sum;
    }
};

class Solution {
    int ans;
    NodeValue validBST(TreeNode* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0); // returned an object

        auto left = validBST(root->left);   // Object of left node
        auto right = validBST(root->right); // Object of right node

        if (left.maxNode < root->val && right.minNode > root->val) { //Condition for valid subtree

            int sum = root->val + left.sum + right.sum;
            ans = max(ans, sum);
            //Maintaing the min and max for all subtrees, as per "valid bst" property the min will come form left and max will come from right
            //If either left or right branch is null then the current node becomes the min and max for the further subtree bst

            return NodeValue(min(root->val, left.minNode), 
                            max(root->val, right.maxNode), 
                            sum); 
        }

        //When its not valid bst therefore for its ancestor 
            //if it is a left branch then its val must be (maxNode) very large so that further tree can be a valid bst
            //if it is a right branch then its val must be (minNode) very small so that further tree can be a valid bst
            //and the best ans shall reach the top
        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum)); 
    }

public:
    int maxSumBST(TreeNode* root) {
        auto final = validBST(root);
        return ans;
    }
};