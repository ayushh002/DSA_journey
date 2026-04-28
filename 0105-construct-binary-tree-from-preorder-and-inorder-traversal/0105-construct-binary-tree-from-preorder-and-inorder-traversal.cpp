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
    unordered_map<int, int> mp;
    void setMap(vector<int>& inorder){
        for(int i = 0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
    }

    TreeNode* getRoot(int index, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder){
        if(inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        int pos = mp[preorder[index]];

        root->left = getRoot(index+1, inStart, pos-1, preorder, inorder);
        root->right = getRoot(index+(pos-inStart)+1, pos+1, inEnd, preorder, inorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        setMap(inorder);
        return getRoot(0, 0, inorder.size()-1, preorder, inorder);
    }
};