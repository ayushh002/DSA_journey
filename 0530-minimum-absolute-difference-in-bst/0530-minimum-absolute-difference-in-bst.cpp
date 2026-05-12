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
    TreeNode* prev = NULL;
    // Inorder gives sorted elements for BST and the minimum difference in a sorted
    // sequence always occurs between adjacent elements.
    void solve(TreeNode* root, int& diff){
        if(!root) return;

        solve(root->left, diff);

        if(prev)
            diff = min(diff, abs(root->val-prev->val));
        prev=root;

        solve(root->right, diff);
    }

    int getMinimumDifference(TreeNode* root) {
        int diff=INT_MAX;
        solve(root, diff);
        return diff;
    }
};