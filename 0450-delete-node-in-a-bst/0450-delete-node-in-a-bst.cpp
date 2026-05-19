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
    int inorderSuccessor(TreeNode* root){
        while(root->left)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        if(key<root->val)
            root->left=deleteNode(root->left, key);
        else if(key>root->val)
            root->right=deleteNode(root->right, key);
        else{
            if(!root->right)
                return root->left;
            else if(!root->left)
                return root->right;
            else{
                root->val=inorderSuccessor(root->right);
                root->right=deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};