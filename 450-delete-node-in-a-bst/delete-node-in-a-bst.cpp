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
    int maxiLeft(TreeNode* maxiNode){
        while(maxiNode -> right -> right != NULL){
            maxiNode = maxiNode -> right;
        }

        int maxi  = maxiNode -> right -> val;
        TreeNode* leftMaxiNode =  maxiNode -> right -> left;
        maxiNode -> right -> left = NULL;
        maxiNode -> right = leftMaxiNode;
        return maxi;
    }

    TreeNode* del(TreeNode* target){
        if(target -> left == NULL){
            TreeNode* temp = target -> right;
            target -> right = NULL;
            return temp;
        }
            
        else if(target -> right == NULL){
            TreeNode* temp = target -> left;
            target -> left = NULL;
            return temp;
        }

        if(target -> left -> right == NULL){
            TreeNode* temp = target -> left;
            temp -> right = target -> right;
            target -> right = NULL;
            return temp;
        } 

        target -> val = maxiLeft(target -> left);
        return target;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        TreeNode* target = root;
        TreeNode* parent = NULL;

        if(target -> val == key) return del(target);

        while(target != NULL){
            if(target -> val > key){
                parent = target;
                target = target -> left;

                if(target != NULL && target -> val == key){
                    parent -> left = del(target);
                    break;
                }
            }
            else if(target -> val < key){
                parent = target;
                target = target -> right;

                if(target != NULL && target -> val == key){
                    parent -> right = del(target);
                    break;
                }
            }

            else break;
        }

        return root;
    }
};