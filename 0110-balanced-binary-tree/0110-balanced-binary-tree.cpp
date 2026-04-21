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
    int check(TreeNode* root, bool& balanced){
        if(!root) return 0;
        if(!balanced) return 0;

        int left = check(root->left, balanced);
        int right = check(root->right, balanced);
        if(abs(left-right)>1)
            balanced = false;
        return 1+max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        check(root, balanced);
        return balanced;
    }
};