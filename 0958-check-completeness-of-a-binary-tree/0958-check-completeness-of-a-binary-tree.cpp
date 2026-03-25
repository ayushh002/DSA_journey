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
    int countNodes(TreeNode* root){
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool checkCBT(TreeNode* root, int index, int total_nodes){
        if(!root) return true;
        if(index>=total_nodes) return false;

        return checkCBT(root->left, 2*index+1, total_nodes) &&
            checkCBT(root->right, 2*index+2, total_nodes);
    }

    bool isCompleteTree(TreeNode* root) {
        // 1. Count the total nodes in the tree
        int total_nodes = countNodes(root);
        // 2. check CBT
        return checkCBT(root, 0, total_nodes);
    }
};