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
        for(int i=0; i<inorder.size(); i++)
            mp[inorder[i]] = i;
    }

    TreeNode* getRoot(int index, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder){
        if(inStart>inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[index]);
        int pos = mp[postorder[index]];

        root->right = getRoot(index-1, pos+1, inEnd, inorder, postorder);
        root->left = getRoot(index-(inEnd-pos)-1, inStart, pos-1, inorder, postorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        setMap(inorder);

        int n = inorder.size();
        return getRoot(n-1, 0, n-1, inorder, postorder);
    }
};