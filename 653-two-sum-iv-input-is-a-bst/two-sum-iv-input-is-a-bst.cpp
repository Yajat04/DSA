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

class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;
    //BSTiterator for both next(LNR) and before(RNL) implementation
    //LNR if reverse = false, RNL for rev = true {next and hasNext used as before and hasBefore}

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if (!reverse)
            pushAll(node->right);
        else
            pushAll(node->left);

        return node->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution {
    //M1: inorder -> sorted therefore apply 2Sum on it
    //M2: Use bst iterator as two pointer(rev = T and F both) and implement 2Sum without using extra space for storing the inorder traversal
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int low = l.next();
        int high = r.next();

        //2Sum
        while(low < high){ //not consider = as it will be same element as valid bst do not store duplicates
            if(low + high == k) return true;
            else if(low + high < k) low = l.next();
            else high = r.next();
        }

        return false;
    }
};