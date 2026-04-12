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
    void solve(TreeNode* root, int& height, int count){
        if(!root){
            height = max(height, count);
            return;
        }

        solve(root->left, height, count+1);
        solve(root->right, height, count+1);
    }

    int maxDepth(TreeNode* root) {
        int height = 0, count = 0;
        solve(root, height, count);
        return height;
    }
};