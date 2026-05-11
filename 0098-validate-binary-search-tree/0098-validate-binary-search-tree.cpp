class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& inorder){
        if(!root) return;
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        for(int i=0; i<inorder.size()-1; i++){
            if(inorder[i]>=inorder[i+1])
                return false;
        }
        return true;
    }
};