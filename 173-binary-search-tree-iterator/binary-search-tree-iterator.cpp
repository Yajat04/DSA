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
    //M1: prepare vector of inorder traversal
    //M2: use stack for inorder traversing
    stack <TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll_left(root);
    }
    
    int next() { //The first time it gets called is when we have the leftmost node at stack top as per LNR sequence of the inorder traversal
        TreeNode* top = st.top();
        st.pop();
        pushAll_left(top -> right);
        return top->val;
    }
    
    bool hasNext() {
        if(st.empty()) return false;
        return true;
    }

    void pushAll_left(TreeNode* root){
        while(root){
            st.push(root);
            root = root -> left;
        }
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */