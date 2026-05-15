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
    TreeNode* solve(int& idx, int min, int max, vector<int>& preorder){
        if(idx==preorder.size())
            return NULL;

        if(preorder[idx]<=min || preorder[idx]>=max)
            return NULL;

        int val=preorder[idx++];
        TreeNode* root=new TreeNode(val);

        root->left=solve(idx, min, val, preorder);
        root->right=solve(idx, val, max, preorder);
        return root;
    }
    // Optimized - O(n) time & space
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(idx, INT_MIN, INT_MAX, preorder);
    }
};