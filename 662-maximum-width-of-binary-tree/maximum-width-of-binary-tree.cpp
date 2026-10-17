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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 1;
        queue <pair<TreeNode* ,int>> q;
        int ans = -1;

        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int mini = q.front().second;

            int first, last;
            for(int i = 0; i < size; i++){
                int curr_idx = q.front().second;
                TreeNode* curr_node = q.front().first;
                q.pop();

                if(i == 0) first = curr_idx;
                if(i == size-1) last = curr_idx;

                int next_ref_idx = curr_idx - mini;
                if(curr_node -> left) q.push({curr_node -> left, (long long)2*next_ref_idx + 1});
                if(curr_node -> right) q.push({curr_node -> right, (long long)2*next_ref_idx + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};